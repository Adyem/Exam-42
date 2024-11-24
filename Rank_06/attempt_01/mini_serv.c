#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int		id;
	char	msg[290000];
} t_client;

t_client	clients[1024];
fd_set		read_set, write_set, current;
int			maxfd = 0, gid = 0;
char		send_buffer[300000], recv_buffer[300000];

void	write_error(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void	send_to_all(int except)
{
	int	fd = 0;
	while (fd <= maxfd)
	{
		if (FD_ISSET(fd, &write_set) && fd != except)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				write_error(NULL);
		fd++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write_error("Wrong nuj,ber of arguments");

	struct sockaddr_in	server_address;
	socklen_t			len;
	int					server_fd = socket(AF_INET, SOCK_STREAM, 0);
	maxfd = server_fd;

	FD_ZERO(&current);
	FD_SET(server_fd, &current);
	bzero(clients, sizeof(server_address));

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(atoi(argv[1]));

	if (bind(server_fd, (const struct sockaddr *)&server_address, sizeof(server_address)) == -1
			|| listen(server_fd, 100) == -1)
		write_error(NULL);
	while (1)
	{
		read_set = write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1)
			continue ;

		int	fd = 0;
		while (fd <= maxfd)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == server_fd)
				{
					int	clientfd = accept(server_fd, (struct sockaddr *)&server_address, &len);

					if (clientfd == -1)
						continue ;
					if (clientfd > maxfd)
						maxfd = clientfd;
					clients[clientfd].id = gid++;
					FD_SET(clientfd, &current);
					sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
					send_to_all(clientfd);
				}
				else
				{
					int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						FD_CLR(fd, &current);
						close(fd);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
					}
					else
					{
						int	i = 0;
						int	j = strlen(clients[fd].msg);
						while (i < ret)
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
