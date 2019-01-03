/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:10:24 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 15:58:16 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	freetab(char **teub)
{
	int		i;

	i = 0;
	while(teub[i])
		free(teub[i++]);
	free(teub);
}

int		main(int ac, char **av)
{
	char	**map;
	int		nb_pieces;
	t_piece	*lst;
	t_piece	*begin;
	char	**solved_map;

	if (ac != 2 || ft_checkvalidmap(av[1]) != 1)
		ft_putstr("error\n");
	else
	{
		map = ft_get_fillit_tab(av[1]);
		nb_pieces = 1;
		while (map[nb_pieces - 1] != NULL)
			nb_pieces++;
		lst = ft_init_list();
		begin = lst;
		lst = ft_fill(map, nb_pieces - 1, lst);
		solved_map = ft_createcanvas(begin, nb_pieces - 1, 0);
		solved_map = ft_solvemap(begin, solved_map, nb_pieces - 1);
		ft_print_map(solved_map);
		//freetab(solved_map);
		//freetab(map);
	}
	return (0);
}
