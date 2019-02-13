/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 15:41:07 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:30:16 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	befree(char **map, char **solved_map)
{
	freetab(solved_map);
	freetab(map);
}

char	**ft_solve_list(int nb_pieces, t_piece *begin)
{
	char **to_solve;

	to_solve = ft_createcanvas(begin, nb_pieces, 0);
	to_solve = ft_solvemap(begin, to_solve, nb_pieces);
	return (to_solve);
}

int		ft_piececpt(char **map)
{
	int	nb_pieces;

	nb_pieces = 0;
	while (map[nb_pieces])
		nb_pieces++;
	return (nb_pieces);
}

int		main(int ac, char **av)
{
	char	**map;
	int		nb_pieces;
	t_piece	*lst;
	t_piece	*begin;
	char	**solved_map;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit [map]\n");
		return (0);
	}
	if (ft_checkvalidmap(av[1]) != 1)
		ft_putstr("error\n");
	else
	{
		map = ft_get_fillit_tab(av[1]);
		nb_pieces = ft_piececpt(map);
		lst = ft_init_list();
		begin = lst;
		lst = ft_fill(map, nb_pieces, lst);
		solved_map = ft_solve_list(nb_pieces, begin);
		ft_print_map(solved_map);
		befree(map, solved_map);
	}
	return (0);
}
