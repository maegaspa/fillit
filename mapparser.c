/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapparser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 15:45:12 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:36:21 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_piece	*ft_fill(char **map, int nb_pieces, t_piece *lst)
{
	int		i;

	i = 0;
	while (i != nb_pieces)
	{
		lst = ft_insert_piece_lst(lst, map[i], i + 1);
		lst = lst->next;
		i++;
	}
	return (lst);
}

t_piece	*ft_init_list(void)
{
	t_piece	*lst;

	if (!(lst = (t_piece *)malloc(sizeof(t_piece))))
		return (0);
	lst->index_piece = 0;
	lst->ligne_a = 0;
	lst->a = 0;
	lst->ligne_b = 0;
	lst->b = 0;
	lst->ligne_c = 0;
	lst->c = 0;
	lst->ligne_d = 0;
	lst->d = 0;
	lst->next = NULL;
	return (lst);
}

t_piece	*ft_insert_piece_lst(t_piece *lst, char *piece, int index)
{
	lst->index_piece = index;
	lst->a = ft_strnchr(piece, '#', 1, 1);
	lst->b = ft_strnchr(piece, '#', 2, 1);
	lst->c = ft_strnchr(piece, '#', 3, 1);
	lst->d = ft_strnchr(piece, '#', 4, 1);
	lst->ligne_a = ft_findline(ft_strnchr(piece, '#', 1, 0));
	lst->ligne_b = ft_findline(ft_strnchr(piece, '#', 2, 0));
	lst->ligne_c = ft_findline(ft_strnchr(piece, '#', 3, 0));
	lst->ligne_d = ft_findline(ft_strnchr(piece, '#', 4, 0));
	lst->next = ft_init_list();
	return (lst);
}

int		ft_findline(int index)
{
	if (index >= 0 && index <= 3)
		return (0);
	if (index >= 4 && index <= 7)
		return (1);
	if (index >= 8 && index <= 11)
		return (2);
	if (index >= 12 && index <= 15)
		return (3);
	return (-1);
}
