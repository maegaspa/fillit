/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapparser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 18:54:46 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 20:14:07 by seanseau    ###    #+. /#+    ###.fr     */
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
	t_piece *lst;

	lst = (t_piece *)malloc(sizeof(t_piece));
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
	int		tmpx;
	int		tmpy;

	tmpx = ft_getzero(piece, 0);
	tmpy = ft_getzero(piece, 1);
	lst->index_piece = index;
	lst->a = ft_strnchr(piece, '#', 1, 1) - tmpx;
	lst->b = ft_strnchr(piece, '#', 2, 1) - tmpx;
	lst->c = ft_strnchr(piece, '#', 3, 1) - tmpx;
	lst->d = ft_strnchr(piece, '#', 4, 1) - tmpx;
	lst->ligne_a = ft_findline(ft_strnchr(piece, '#', 1, 0)) - tmpy;
	lst->ligne_b = ft_findline(ft_strnchr(piece, '#', 2, 0)) - tmpy;
	lst->ligne_c = ft_findline(ft_strnchr(piece, '#', 3, 0)) - tmpy;
	lst->ligne_d = ft_findline(ft_strnchr(piece, '#', 4, 0)) - tmpy;
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

int		ft_getzero(char *piece, int on)
{
	int tmpx;
	int tmpy;

	tmpy = 0;
	tmpx = 0;
	if (on == 0)
	{
		tmpx = ft_strnchr(piece, '#', 1, 1);
		while (tmpx > ft_strnchr(piece, '#', 2, 1) || tmpx > ft_strnchr(piece,
					'#', 3, 1) || tmpx > ft_strnchr(piece, '#', 4, 1))
			tmpx--;
		return (tmpx);
	}
	if (on == 1)
	{
		tmpy = ft_findline(ft_strnchr(piece, '#', 1, 0));
		while (tmpy > ft_findline(ft_strnchr(piece, '#', 2, 0)) || tmpy >
				ft_findline(ft_strnchr(piece, '#', 3, 0)) || tmpy >
				ft_findline(ft_strnchr(piece, '#', 4, 0)))
			tmpy--;
		return (tmpy);
	}
	return (-1);
}
