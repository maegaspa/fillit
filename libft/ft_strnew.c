/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:58:19 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:52:23 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *tmp;

	if ((tmp = (char *)malloc(sizeof(*tmp) * (len + 1))) == NULL)
		return (NULL);
	ft_bzero(tmp, len + 1);
	return (tmp);
}
