/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 15:53:42 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 20:11:23 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_countpiece_fd(int fd)
{
	char	line[1];
	int		res;
	int		nb_line;
	int		nb_pieces;
	int		tmp;

	nb_line = 0;
	nb_pieces = 0;
	while ((res = read(fd, line, 1)) > 0)
	{
		if (line[0] == '\n')
			nb_line++;
	}
	tmp = nb_line;
	while (nb_line > 0)
	{
		nb_line = nb_line - 5;
		nb_pieces++;
	}
	if (((nb_pieces * 5) - 1) == tmp)
		return (nb_pieces);
	return (-1);
}

void	ft_print_map(char **map)
{
	int a;

	a = 0;
	while (map[a])
	{
		ft_putstr(map[a]);
		a++;
	}
}
