#include "get_next_line_bonus.h"

#define BUFFER_SIZE 5

int					conditionals(int reading, char *buf, char **ost,
					char **line)
{
	t_strdup		per;

	per.tmp = NULL;
	if (reading < 0)
	{
		free(buf);
		return (-1);
	}
	buf[reading] = '\0';
	if (reading == 0)
	{
		free(buf);
		free(*ost);
		return (0);
	}
	if (ft_strchr(buf, '\n'))
	{
		per.tmp2 = ft_strchr(buf, '\n');
		*ost = ft_strdup_n_free(per.tmp2, ost);
		per.tmp = ft_strdup_n_free(buf, &(per.tmp));
		*line = ft_strjoin_free(*line, &(per.tmp));
		free(per.tmp);
		return (1);
	}
	return (3);
}

int					reading_text(int fd, char *buf, char **line, char **ost)
{
	int				reading;
	int				res;

	reading = 1;
	while (reading)
	{
		reading = read(fd, buf, BUFFER_SIZE);
		res = conditionals(reading, buf, ost, line);
		if (res == 1)
			return (1);
		else if (res == 0)
			return (0);
		else if (res == -1)
			return (-1);
		*line = ft_strjoin_free(*line, &buf);
	}
	return (0);
}

int					check_ost(char **ost, char **line)
{
	char			*tmp;

	if (*ost)
	{
		if (ft_strchr(*ost, '\n'))
		{
			tmp = ft_strchr(*ost, '\n');
			tmp = ft_strdup_n_free(tmp, line);
			*line = ft_strdup_n_free(*ost, ost);
			*ost = tmp;
			return (1);
		}
		*line = ft_strdup_n_free(*ost, line);
		free(*ost);
		*ost = NULL;
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*ost[1024];
	t_strdup		struc;

	struc.buf = NULL;
	if (fd < 0 || !(line) || BUFFER_SIZE < 1 || read(fd, struc.buf, 0) == -1)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	**line = '\0';
	if (ost[fd])
		if (check_ost(&ost[fd], line))
			return (1);
	if (!(struc.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	struc.count = BUFFER_SIZE + 1;
	while (struc.count--)
		struc.buf[struc.count] = '\0';
	if ((struc.count = reading_text(fd, struc.buf, line, &ost[fd])) != 0)
	{
		(struc.buf) ? free(struc.buf) : struc.buf;
		struc.buf = NULL;
		return ((struc.count == 1) ? 1 : -1);
	}
	return (0);
}
