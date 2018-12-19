/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapprinter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 11:33:03 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:18:59 by seanseau    ###    #+. /#+    ###.fr     */
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
