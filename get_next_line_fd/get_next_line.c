#include "get_next_line.h"

static char	*new_line(char *line)
{
	char	*new_line;
	char	*reste;

	new_line = ft_strchr(line, '\n');
	if (!new_line)
		return (NULL);
	reste = ft_strdup(new_line + 1);
	new_line++;
	if (!reste)
		return (NULL);
	*new_line = '\0';
	return (reste);
}

static char	*read_line(char *line, int fd, char *buffer)
{
	char	*temp;
	int		bytes;

	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 1)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
			return (NULL);
		free (line);
		line = temp;
	}
	if (*line == '\0')
	{
		free (line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*dest[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free (dest[fd]);
		free (buffer);
		dest[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_line(dest[fd], fd, buffer);
	free (buffer);
	if (!line || *line == '\0')
	{
		free(line);
		dest[fd] = NULL;
		return (NULL);
	}
	dest[fd] = new_line(line);
	return (line);
}
