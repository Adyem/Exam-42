#include "get_next_line.h"

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

char	*ft_strjoin(char *string1, char *string2)
{
	int		i;
	int		j;
	char	*result;

	if (!string1 && !string2)
		return (NULL);
	result = (char *)malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (string1)
	{
		while (string1[i])
		{
			result[i] = string1[i];
			i++;
		}
	}
	j = 0;
	if (string2)
	{
		while (string2[j])
		{
			result[i] = string2[j];
			i++;
			j++;
		}
	}
	result[i] = '\0';
	free(string1);
	return (result);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	int		readed_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed_bytes = 1;
	while (!ft_strchr(line, '\n') && readed_bytes > 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	free(buffer);
	return(line);
}

char	*fetch_line(char *line)
{
	char	*rline;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	rline = (char *)malloc(i + 2);
	if (!rline)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		rline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		rline[i] = '\n';
		i++;
	}
	rline[i] = '\0';
	return (rline);
}

char	*leftovers(char	*line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	result = (char *)malloc(ft_strlen(line) - i + 1);
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		result[j] = line[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line;
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
