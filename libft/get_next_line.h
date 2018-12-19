/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gnl.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 14:11:17 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 21:16:46 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 1000
# include <stdlib.h>
# include <stdio.h>

char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*ft_strnew(size_t size);
int		get_next_line(int const fd, char **line);

#endif
