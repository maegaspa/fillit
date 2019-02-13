/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapconverter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 16:32:50 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 20:13:35 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**ft_get_fillit_tab(char *str)
{
	char	**tab;
	int		fd;
	int		nb_pieces;

	fd = open(str, O_RDONLY);
	nb_pieces = ft_countpiece_fd(fd);
	close(fd);
	tab = ft_getcontent(str, nb_pieces);
	return (tab);
}

char	**ft_getcontent(char *str, int nb_pieces)
{
	char	**tab;
	int		i;
	int		fd;

	if (!(tab = malloc(sizeof(char *) * (nb_pieces + 1))))
		return (NULL);
	i = 0;
	while (i < nb_pieces)
		tab[i++] = NULL;
	i = 0;
	fd = open(str, O_RDONLY);
	while (i < nb_pieces)
	{
		tab[i] = ft_getvalidsegment(fd, nb_pieces);
		i++;
	}
	tab[i] = 0;
	close(fd);
	return (tab);
}

char	*ft_getvalidsegment(int fd, int nb_pieces)
{
	int		i;
	char	line[5];
	int		ret;
	char	*seg;
	char	*tmp;

	seg = ft_strnew(16);
	i = 4;
	while (i > 0 && (ret = read(fd, line, 4) > 0))
	{
		tmp = ft_strsub(line, 0, 4);
		if (nb_pieces > 0)
			if ((read(fd, line, 1) > 0))
				;
		seg = ft_strcat(seg, tmp);
		free(tmp);
		i--;
	}
	if (nb_pieces > 1)
		if ((read(fd, line, 1)) > 0)
			;
	seg[16] = '\0';
	return (seg);
}
