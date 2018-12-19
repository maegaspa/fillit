/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mapconverter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 17:57:13 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 13:12:09 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**ft_get_fillit_tab(char *str)
{
	char	**tab;
	int		fd;
	int		fdp;
	int		nb_pieces;

	fdp = open(str, O_RDONLY);
	nb_pieces = ft_countpiece(fdp);
	close(fdp);
	fd = open(str, O_RDONLY);
	tab = ft_getcontent(fd, nb_pieces);
	close(fd);
	return (tab);
}

char	**ft_getcontent(int fd, int nb_pieces)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (nb_pieces + 2));
	i = 0;
	if (!tab[i])
		tab[i] = ft_strnew(0);
	while (tab[i] != NULL)
	{
		tab[i] = ft_getvalidsegment(fd);
		if (tab[i] != NULL)
			tab[i + 1] = ft_strnew(0);
		i++;
	}
	return (tab);
}

char	*ft_getvalidsegment(int fd)
{
	int		x;
	char	*line;
	int		res;
	char	*seg;

	seg = ft_strnew(0);
	x = 5;
	while (x-- && (res = get_next_line(fd, &line) > 0))
	{
		seg = ft_strcat(seg, line);
		//free(line);
	}
	if (x == -1 || (x == 0 && res == 0))
		return (ft_algo_vert_horiz(seg));
	return (NULL);
}

char	*ft_algo_vert_horiz(char *str)
{
	char	*tmp;

	while ((str[0] == '.') && (str[4] == '.')
			&& (str[8] == '.') && (str[12] == '.'))
	{
		tmp = str;
		str = ft_strsub(tmp, 1, ft_strlen(str));
	//	free(tmp);
		str = ft_strcat(str, ".");
	}
	while ((str[0] == '.') && (str[1] == '.')
			&& (str[2] == '.') && (str[3] == '.'))
	{
		tmp = str;
		str = ft_strsub(tmp, 4, ft_strlen(str));
		//free(tmp);
		str = ft_strcat(str, "....");
	}
	return (str);
}

int		ft_countpiece(int fdp)
{
	char	*line;
	int		res;
	int		nb_line;
	int		nb_pieces;

	nb_line = 0;
	nb_pieces = 0;
	while ((res = get_next_line(fdp, &line) > 0))
	{
		nb_line++;
		//free(line);
	}
	while (nb_line > 0)
	{
		nb_line = nb_line - 5;
		nb_pieces++;
	}
	return (nb_pieces);
}
