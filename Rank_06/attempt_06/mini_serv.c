#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int		id;
	char	msg[290000];
}	t_client;

fd_set			write_set, read_set, current;
struct sockaddr		server_adress;
int				max_fd = 0, gid = 0;
char			send_buffer[300000], recv_buffer[300000];

void	write_error(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
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
		if (FD_ISSET(fd, &current))
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				write_error(NULL);
		fd++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write_error("Wrong nu,ber of arguments");
	return (0);

	struct sockaddr_in	server_address;
	socklen_t			len;
	
	int	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	max_fd = server_fd;

	FD_ZERO(&current);
	FD_SET(server_fd, &current);
}
