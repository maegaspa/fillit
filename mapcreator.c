/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapcreator.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 19:58:22 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:00:41 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_tabtab(char **map, int cotemin)
{
	int		x;
	int		y;
	char	*tmp;

	x = -1;
	while (++x < cotemin)
	{
		y = -1;
		map[x] = ft_strnew(cotemin);
		while (++y < cotemin)
		{
			tmp = map[x];
			map[x] = ft_strjoin(map[x], ".");
			free(tmp);
		}
		map[x][y] = '\n';
		map[x][cotemin + 1] = '\0';
	}
	map[x] = 0;
	return (map);
}

char	**ft_createcanvas(t_piece *curr, int nb_pieces, int z)
{
	int		cotemin;
	char	**map;

	cotemin = ft_skurt(nb_pieces * 4) + z;
	while (nb_pieces == 1 && (curr->ligne_d >= cotemin || curr->d >= cotemin))
		cotemin++;
	if (!(map = (char **)malloc(sizeof(*map) * (cotemin + 1))))
		return (NULL);
	return (ft_tabtab(map, cotemin));
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
