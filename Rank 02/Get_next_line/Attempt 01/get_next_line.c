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

char	*ft_strjoin(char *string1, char *string2)
{
	char	*original_string;
	char	*result;
	int		i;

	(void)original_string;
	if (!string1 && !string2)
		return (NULL);
	result = (char *)malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	if (!result)
		return (NULL);
	original_string = string1;
	i = 0;
	if (string1)
		while (*string1)
			result[i++] = *string1++;
	if (string2)
		while (*string2)
			result[i++] = *string2++;
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(char *string, int c)
{
	int		i;

	if (!string)
		return(NULL);
	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)string);
	return (NULL);
}

char	*read_fd(int fd, char *readed_string)
{
	char	*buffer;
	int		readed_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed_bytes = 1;
	while (!ft_strchr(readed_string, '\n') && readed_bytes)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buffer);
			free(readed_string);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		readed_string = ft_strjoin(readed_string, buffer);
		if (!readed_string)
			return (NULL);
	}
	return (readed_string);
}

char	*ft_realloc(char *readed_string)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(ft_strlen(readed_string) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (readed_string[i])
	{
		temp[i] = readed_string[i];
		i++;
	}
	temp[i] = '\0';
	free (readed_string);
	return (temp);
}

char	*leftovers(char *readed_string)
{
	char	*line;
	char	*temp2;
	char	*temp;
	int		i;

	temp = ft_strchr(readed_string, '\n');
	if (!temp)
		return (readed_string);
	temp2 = (char *)malloc(ft_strlen(temp) + 1);
	if (!temp2)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		temp2[i] = temp[i];
		temp[i] = '\0';
		i++;
	}
	temp2[i] = '\0';
	line = ft_realloc(readed_string);
	readed_string = temp2;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed_string;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	readed_string = read_fd(fd, readed_string);
	if (!readed_string)
		return(NULL);
	line = leftovers(readed_string);
	return (line);
}
