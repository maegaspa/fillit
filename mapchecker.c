/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapchecker.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 15:49:42 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:58:01 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_checkvalidmap(char *str)
{
	int fd;
	int nb_pieces;
	int res;

	res = 1;
	fd = open(str, O_RDONLY);
	if ((nb_pieces = ft_countpiece_fd(fd)) < 1)
		return (-1);
	close(fd);
	fd = open(str, O_RDONLY);
	while (nb_pieces > 0 && res == 1)
		res = ft_checkvalidsegment(fd, nb_pieces--);
	close(fd);
	return (res);
}

int		ft_checkvalidsegment(int fd, int nb_pieces)
{
	int		i;
	char	line[5];
	int		ret;
	char	*seg;
	char	*tmp;

	seg = ft_strnew(0);
	i = 4;
	while (i > 0 && (ret = read(fd, line, 4) > 0))
	{
		tmp = ft_strsub(line, 0, 4);
		if (nb_pieces > 0)
			if ((read(fd, line, 1) > 0))
				;
		seg = ft_strcat(seg, tmp);
		free(tmp);
		i--;
	}
	if (nb_pieces > 1)
		if ((read(fd, line, 1)) > 0)
			;
	tmp = seg;
	free(seg);
	return (ft_checkvalidchar(tmp));
}

int		ft_checkvalidchar(char *str)
{
	int		y;
	int		nb_diez;

	y = 0;
	nb_diez = 0;
	while (str[y])
	{
		if (str[y] == '#')
		{
			nb_diez++;
			if (!(str[y + 4] == '#' || str[y + 1] == '#'
						|| str[y - 4] == '#' || str[y - 1] == '#'))
				nb_diez++;
		}
		y++;
	}
	if (y != 16 || nb_diez != 4 || ft_isfillit(str) == 0 ||
			ft_checkshape(str) == 0)
		return (-1);
	else
		return (1);
}

int		ft_checkshape(char *str)
{
	int		total_links;
	int		i;

	total_links = 0;
	i = 0;
	while (i < 4)
	{
		total_links += ft_checklink(ft_strnchr(str, '#', i + 1, 0), str);
		i++;
	}
	if (total_links == 6 || total_links == 8)
		return (1);
	return (0);
}

int		ft_checklink(int x, char *str)
{
	int		nb_link_piece;
	int		len;

	len = ft_strlen(str);
	nb_link_piece = 0;
	if (str[x + 1] == '#' && x + 1 < len)
		nb_link_piece++;
	if (str[x - 1] == '#' && x - 1 >= 0)
		nb_link_piece++;
	if (str[x + 4] == '#' && x + 4 < len)
		nb_link_piece++;
	if (str[x - 4] == '#' && x - 4 >= 0)
		nb_link_piece++;
	return (nb_link_piece);
}
