/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapsolver.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 19:55:53 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:29:29 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**ft_solvemap(t_piece *lst, char **map, int nb_pieces)
{
	int		tabsize;
	t_piece *begin;
	int		i;

	i = 0;
	begin = lst;
	tabsize = 0;
	while (map[0][tabsize + 1])
		tabsize++;
	while (place_pieces(lst, &map, tabsize, nb_pieces) == 0)
	{
		while (map[tabsize])
			tabsize++;
		tabsize++;
		while (map[i])
			free(map[i++]);
		free(map);
		map = ft_createcanvas(lst, nb_pieces, 1);
	}
	while (begin)
	{
		free(begin);
		begin = begin->next;
	}
	return (map);
}

int		place_pieces(t_piece *curr, char ***map, int tabsize, int nb_pieces)
{
	int		pos;

	pos = 0;
	if (curr == NULL)
		return (1);
	if (curr->index_piece == 0)
		return (1);
	while (pos < (tabsize * tabsize))
	{
		if (valid_pos(curr, map, pos, tabsize) == 1)
		{
			place_for_real(curr, pos, map, tabsize);
			if (place_pieces(curr->next, map, tabsize, nb_pieces) == 1)
				return (1);
			ft_erase_piece(curr, pos, map, tabsize);
		}
		pos++;
	}
	return (0);
}

int		valid_pos(t_piece *lst, char ***map, int pos, int tabsize)
{
	int pos_y;
	int pos_x;

	pos_y = get_pos(pos, 1, tabsize);
	pos_x = get_pos(pos, 2, tabsize);
	if ((lst->ligne_d + pos_y >= tabsize) || (lst->d + pos_x >= tabsize))
		return (0);
	if ((*map)[lst->ligne_a + pos_y][lst->a + pos_x] == '.' &&
			(*map)[lst->ligne_b + pos_y][lst->b + pos_x] == '.' &&
			(*map)[lst->ligne_c + pos_y][lst->c + pos_x] == '.' &&
			(*map)[lst->ligne_d + pos_y][lst->d + pos_x] == '.')
		return (1);
	return (0);
}

void	place_for_real(t_piece *lst, int pos, char ***map, int tabsize)
{
	int	pos_x;
	int pos_y;

	pos_y = get_pos(pos, 1, tabsize);
	pos_x = get_pos(pos, 2, tabsize);
	(*map)[lst->ligne_a + pos_y][lst->a + pos_x] = 64 + lst->index_piece;
	(*map)[lst->ligne_b + pos_y][lst->b + pos_x] = 64 + lst->index_piece;
	(*map)[lst->ligne_c + pos_y][lst->c + pos_x] = 64 + lst->index_piece;
	(*map)[lst->ligne_d + pos_y][lst->d + pos_x] = 64 + lst->index_piece;
}

int		get_pos(int pos, int z, int tabsize)
{
	int	position;

	position = 0;
	while (pos >= tabsize)
	{
		pos = pos - tabsize;
		position++;
	}
	if (z == 1)
		return (position);
	return (pos);
}
