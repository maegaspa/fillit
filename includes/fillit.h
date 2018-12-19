/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 16:47:00 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:09:33 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

char				**ft_get_fillit_tab(char *str);
char				*ft_algo_vert_horiz(char *str);
char				**ft_getcontent(int fd, int nb_pieces);
int					ft_countpiece(int fdp);
char				*ft_getvalidsegment(int fd);
int					ft_checkvalidmap(char *str);
int					ft_checkvalidsegment(int fd);
int					ft_checkvalidchar(char *str);
int					ft_findline(int index);
int					ft_checksolvedmap(char **map);
void				ft_print_map(char **map);
void				ft_eraseline(char ***map, int a);
int					ft_checkjoint(char *str);

typedef	struct		s_piece
{
	int				index_piece;
	int				a;
	int				b;
	int				c;
	int				d;
	int				ligne_a;
	int				ligne_b;
	int				ligne_c;
	int				ligne_d;
	struct s_piece	*next;
}					t_piece;

t_piece				*ft_fill(char **map, int nb_pieces, t_piece *lst);
t_piece				*ft_insert_piece_lst(t_piece *lst, char *piece, int index);
t_piece				*ft_init_list(void);
char				**ft_createcanvas(t_piece *curr, int nb_pieces, int z);
int					place_pieces(t_piece *curr, char ***map, int tabsize,
		int nb_pieces);
int					valid_pos(t_piece *lst, char ***map, int pos, int tabsize);
void				place_for_real(t_piece *lst, int pos, char ***map,
		int tabsize);
int					get_pos(int pos, int z, int tabsize);
char				**ft_solvemap(t_piece *lst, char **mapu, int nb_pieces);
void				ft_erase_piece(t_piece *curr, int pos, char ***map,
		int tabsize);
char				**ft_add_canvas_line(char **map,
		int nb_line, int nb_pieces);
char				**ft_fillnewcanvas(char **temp, char **map, int x);

#endif
