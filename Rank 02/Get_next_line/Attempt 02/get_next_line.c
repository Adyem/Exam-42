#include "get_next_line.h"

char	*ft_strchr(char *string, int c)
{
	if (!string)
		return (NULL);
	while (*string)
	{
		if (*string == (char)c)
			return (string);
		string++;
	}
	if ((char)c == '\0')
		return (string);
	return (NULL);
}

int		ft_strlen(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *string1, char *string2)
{
	char	*result;
	int		i;
	int 	j;

	if (!string1 && !string2)
		return (NULL);
	result = (char *)malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (string1)
	{
		while (string1[i])
		{
			result[i] = string1[i];
			i++;
		}
	}
	if (string2)
	{
		while (string2[i])
		{
			result[i] = string2[i];
			i++;
			j++;
		}
	}
	result[i] = '\0';
	free (string1);
	return (result);
}

char	*read_line(int fd, char *line)
{
	int		i;
	int		readed_bytes;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
	readed_bytes = 1;
	while (!ft_strchr(line, '\n') && readed_bytes > 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	free(buffer);
	return (line);
}

char	*leftovers(char *readed_string)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (readed_string[i] && readed_string[i] != '\n')
		i++;
	if (!readed_string[i])
	{
		free(readed_string);
		return (NULL);
	}
	string = (char *)malloc(ft_strlen(readed_string) - i + 1);
	if (!string)
		return (NULL);
	i++;
	j = 0;
	while (readed_string[i])
		string[j++] = readed_string[i++];
	string[j] = '\0';
	free(readed_string);
	return (string);
}

char	*malloc_gnl(char *readed_string, size_t i)
{
	char	*string;

	if (readed_string && readed_string[i] == '\n')
		string = (char *)malloc(i + 2);
	else
		string = (char *)malloc(i + 1);
	if (!string)
		return (NULL);
	return (string);
}

char	*fetch_line(char *readed_string)
{
	size_t	i;
	char	*string;

	i = 0;
	if (!readed_string[i])
		return (NULL);
	while (readed_string[i] && readed_string[i] != '\n')
		i++;
	string = malloc_gnl(readed_string, i);
	if (!string)
		return (NULL);
	i = 0;
	while (readed_string[i] && readed_string[i] != '\n')
	{
		string[i] = readed_string[i];
		i++;
	}
	if (readed_string[i] == '\n')
	{
		string[i] = '\n';
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char *line;
	char		*rline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	rline = fetch_line(line);
	line = leftovers(line);
	return (rline);
}
