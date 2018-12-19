/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 14:57:03 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 17:31:24 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

char				*ft_strndup(const char *s, size_t n);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_sqrt(int nb);
int					ft_recursive_factorial(int nb);
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str,
		const char *to_find, size_t slen);
char				*ft_strcat(char *dest, const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *dest, const char *src, int nb);
int					ft_atoi(char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
size_t				ft_isfillit(char *str);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strchr(const char *s, int c);
int					ft_strnchr(const char *s, int c, int occurence, int on);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_itoa(int n);
char				*ft_strrev(char *str);
int					get_next_line(int fd, char **line);
int					ft_skurt(int nb);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif