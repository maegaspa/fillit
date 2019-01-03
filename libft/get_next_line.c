/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 17:54:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:00:49 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_read(int fd, char **line, char *buf)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (!(ft_strchr(tmp, '\n')) && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret)
		{
			buf[ret] = '\0';
			tmp = *line;
			if (!(*line = ft_strjoin(*line, buf)))
				return (NULL);
			free(tmp);
		}
	}
	free(buf);
	return (*line);
}

char		*get_stocked(char **line)
{
	char	*tmp;
	char	*str;
	char	*buf;

	buf = ft_strchr(*line, '\n');
	tmp = NULL;
	if (buf)
	{
		if (!(str = ft_strndup(*line, buf - *line)))
			return (NULL);
		tmp = *line;
		if (!(*line = ft_strdup(buf + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(str = ft_strdup(*line)))
		return (NULL);
	if (!(*line) || !tmp)
	{
		free(*line);
		*line = NULL;
	}
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tmp[10240];
	char			*buf;

	if (line == '\0' || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)) ||
			read(fd, buf, 0) == -1 ||
			(tmp[fd] == NULL && !(tmp[fd] = ft_strnew(0))))
		return (-1);
	if (!(get_read(fd, &tmp[fd], buf)))
		return (-1);
	if (*tmp[fd])
	{
		if (!(*line = get_stocked(&tmp[fd])))
			return (-1);
		return (1);
	}
	return (0);
}
