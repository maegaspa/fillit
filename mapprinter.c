/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapprinter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 11:33:03 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/03 15:58:52 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_print_map(char **map)
{
	int a;
	int pos_ar;

	pos_ar = 0;
	a = 0;
	while (map[a])
	{
		if (ft_strchr(map[a], '@') != NULL)
		{
			pos_ar = ft_strnchr(map[a], '@', 1, 0);
			map[a][pos_ar] = '.';
		}
		ft_putstr(map[a]);
		a++;
	}
}
