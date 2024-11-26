#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_client
{
	int		id;
	char	msg[290000];
}	t_client;

t_client	clients[1024];
fd_set		write_set, read_set, current;
int			max_fd = 0, gid = 0;
char		recv_buffer[300000], send_buffer[300000];

void	write_error(char *msg)
{
	if (msg)
		write (2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void	send_to_all(int exception)
{
	int	fd = 0;
	while (fd <= max_fd)
	{
		if (FD_ISSET(fd, &write_set))
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				write_error(NULL);
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write_error("Wrong number of arguments");

	struct sockaddr_in	server_addres;
	socklen_t			len;
	int	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
		write_error(NULL);
	max_fd = server_fd;

	FD_ZERO(&current);
	FD_SET(server_fd, &current);

	bzero(clients, sizeof(clients));
	bzero(&server_addres, sizeof(server_addres));

	server_addres.sin_family = AF_INET;
	server_addres.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addres.sin_port = htons(atoi(argv[1]));

	if (bind(server_fd, (const struct sockaddr *)&server_addres, sizeof(server_addres)) == -1
			|| listen(server_fd, 100) == -1)
		write_error(NULL);

	while (1)
	{
		read_set = write_set = current;
		if (select(max_fd + 1, &read_set, &write_set, 0, 0) == -1)
			continue ;

		int fd = 0;
		while (fd <= max_fd)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == server_fd)
				{
					int	client_fd = accept(server_fd, (struct sockaddr *)&server_addres, &len);
					if (client_fd == -1)
						write_error(NULL);
					if (client_fd > max_fd)
						max_fd = client_fd;

					FD_SET(client_fd, &current);
					clients[client_fd].id = gid++;
					sprintf(send_buffer, "client %d has arrived", clients[client_fd].id);
					send_to_all(client_fd);
				}
				else
				{
					int	readed_bytes = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if (readed_bytes <= 0)
					{
						sprintf(send_buffer, "server: client %d has left", clients[fd].id);
						send_to_all(fd);
						close(fd);
						FD_CLR(fd, &current);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
					}
					else
					{
						int i = 0;
						int j = strlen(clients[fd].msg);
						while (i < readed_bytes)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s",
										clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}
							i++;
							j++;
						}
					}
				}
				break ;
			}
			fd++;
		}
	}
	return (0);
}
