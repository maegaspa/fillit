/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 15:13:06 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 10:34:14 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchr(const char *s, int c, int occurence, int on)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			k++;
			if (k == occurence)
			{
				if (on == 1)
					while (i > 3)
						i = i - 4;
				return (i);
			}
		}
		i++;
	}
	return (0);
}
