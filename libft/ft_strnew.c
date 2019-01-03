/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:52:48 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 14:56:47 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*lilchain;
	unsigned int		i;

	i = 0;
	if (!(lilchain = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size + 1)
	{
		lilchain[i] = '\0';
		i++;
	}
	return (lilchain);
}
