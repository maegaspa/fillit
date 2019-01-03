/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapchecker.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 17:57:28 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 16:36:56 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_checkvalidmap(char *str)
{
	int	res;
	int	fd;

	res = 1;
	fd = open(str, O_RDONLY);
	while (res == 1)
		res = ft_checkvalidsegment(fd);
	close(fd);
	if (res == 0)
		return (1);
	if (res < 0)
		return (0);
	return (-1);
}

int		ft_checkvalidsegment(int fd)
{
	int		x;
	char	*line;
	int		ret;
	char	*seg;
	int		tmp;

	seg = ft_strnew(0);
	x = 5;
	while (x-- && (ret = get_next_line(fd, &line) > 0))
	{
		seg = ft_strcat(seg, line);
		//free(line);
	}
	tmp = ft_checkvalidchar(seg);
	free(seg);
	if (x == -1)
		return (tmp);
	if (x == 0 && ret == 0)
		return (tmp - 1);
	return (-1);
}

int		ft_checkvalidchar(char *str)
{
	int		y;
	int		nb_diez;
	int		tmp;

	y = 0;
	nb_diez = 0;
	while (str[y])
	{
		if (str[y] == '#')
		{
			tmp = y;
			nb_diez++;
			if (!(str[y + 4] == '#' || str[y + 1] == '#'
						|| str[y - 4] == '#' || str[y - 1] == '#'))
				nb_diez++;
		}
		y++;
	}
	if (y != 16 || nb_diez != 4 || ft_isfillit(str) == 0 ||
			ft_checkjoint(str) == 0)
		return (-1);
	else
		return (1);
}

int		ft_checksolvedmap(char **map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (map[0][a])
		a++;
	while (b < a - 1)
	{
		ft_putstr(map[b]);
		b++;
	}
	return (b);
}

int		ft_checkjoint(char *str)
{
	if ((ft_strnchr(str, '#', 2, 0) == ft_strnchr(str, '#', 3, 0) - 1) ||
			(ft_strnchr(str, '#', 2, 0) == ft_strnchr(str, '#', 3, 0) - 4) ||
			(ft_strnchr(str, '#', 2, 0) == ft_strnchr(str, '#', 3, 0) - 3) ||
			(ft_strnchr(str, '#', 2, 0) == ft_strnchr(str, '#', 3, 0) - 2))
	{
		if (ft_strnchr(str, '#', 2, 0) == ft_strnchr(str, '#', 3, 0) - 2)
		{
			if (ft_strnchr(str, '#', 1, 0) == ft_strnchr(str, '#', 4, 0) - 4)
				return (1);
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
