/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapcreator.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 17:34:34 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 13:08:15 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_createcanvas(t_piece *curr, int nb_pieces, int z)
{
	int		cotemin;
	char	**map;
	char	*tmp;
	int		x;
	int		y;

	x = 0;
	cotemin = ft_skurt(nb_pieces * 4) + z;
	while (nb_pieces == 1 && (curr->ligne_d >= cotemin || curr->d >= cotemin))
		cotemin++;
	if (!(map = (char **)malloc(sizeof(*map) * (cotemin - 1))))
		return (NULL);
	while (x < cotemin)
	{
		y = 0;
		map[x] = ft_strnew(cotemin + 1);
		while (y < cotemin)
		{
			tmp = map[x];
			map[x] = ft_strjoin(tmp, ".");
			//free(tmp);
			y++;
		}
		tmp = map[x];
		map[x] = ft_strjoin(tmp, "\n");
		//free(tmp);
		x++;
	}
	return (map);
}

void	ft_erase_piece(t_piece *lst, int pos, char ***map, int tabsize)
{
	int pos_x;
	int pos_y;

	pos_y = get_pos(pos, 1, tabsize);
	pos_x = get_pos(pos, 2, tabsize);
	(*map)[lst->ligne_a + pos_y][lst->a + pos_x] = '.';
	(*map)[lst->ligne_b + pos_y][lst->b + pos_x] = '.';
	(*map)[lst->ligne_c + pos_y][lst->c + pos_x] = '.';
	(*map)[lst->ligne_d + pos_y][lst->d + pos_x] = '.';
}
