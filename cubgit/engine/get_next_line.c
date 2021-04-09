#include "../cub3d.h"

int		ft_emptybuffer(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_renewbuffer(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] == '\0' && i < BUFFER_SIZE)
		i++;
	while (buff[i] != '\n' && buff[i] && i < BUFFER_SIZE)
		buff[i++] = '\0';
	buff[i] = '\0';
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	buffer[BUFFER_SIZE + 1];
	size_t			count;

	if (fd < 0 || read(fd, buffer, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strnew(1);
	count = BUFFER_SIZE;
	while (1)
	{
		if (ft_emptybuffer(buffer))
		{
			count = read(fd, buffer, BUFFER_SIZE);
			if (count == 0)
				return (0);
		}
		*line = ft_stjoin(*line, buffer);
		if (ft_iscinstr('\n', buffer, BUFFER_SIZE))
			return (ft_renewbuffer(buffer));
		else
		{
			ft_renewbuffer(buffer);
			if (count != BUFFER_SIZE)
				return (0);
		}
	}
	free(line);
}
