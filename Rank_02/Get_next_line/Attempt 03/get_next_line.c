#include "get_next_line.h"

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
	string = (char *)malloc(ft_strlen(readed_string + 1));
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

char	*fetch_line(char *readed_string)
{
	int		i;
	char	*line;

	i = 0;
	if (!readed_string[i])
		return (NULL);
	while (readed_string[i] && readed_string[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (readed_string[i] && readed_string[i] != '\n')
	{
		line[i] = readed_string[i];
		i++;
	}
	if (readed_string[i] == '\n')
	{
		line[i] = readed_string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_strlen(char *string)
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
	int		j;
	int		i;	
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

char	*read_line(int fd, char *readed_line)
{
	char	*buffer;
	int		readed_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed_bytes = 1;
	while (!ft_strchr(readed_line, '\n') && readed_bytes > 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free (buffer);
			free (readed_line);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		readed_line = ft_strjoin(readed_line, buffer);
		if (!readed_line)
			return (NULL);
	}
	free(buffer);
	return (readed_line);
}

char	*get_next_line(int fd)
{
	static char	*readed_line;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	readed_line = read_line(fd, readed_line);
	if (!readed_line)
		return (NULL);
	line = fetch_line(readed_line);
	readed_line = leftovers(readed_line);
	return (line);
}
