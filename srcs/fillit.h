/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:14:32 by seronen           #+#    #+#             */
/*   Updated: 2019/12/22 15:11:31 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "libft.h"
# include <fcntl.h>

typedef struct		s_coord
{
	int					c1;
	int					c2;
	int					c3;
	int					c4;
	int					let;
	struct s_coord		*next;
}					t_coord;

void				ft_delete_list(t_list *current);
void				ft_error(int err);
int					ft_validate_block(char *s);
int					ft_prepare(t_list *head, int x);
char				*ft_make_map_xy(int x);
t_coord				*ft_lstnew_coord(void);
t_coord				*ft_make_coord(t_list *node);
int					ft_manager(t_list *head, t_coord *coord, int mapsize);
t_list				*ft_mod_block(t_list *head, int mapsize);
int					ft_check_square(t_coord *c);
int					ft_check_4block(t_coord *c);
void				ft_check_bc(t_list *h);
void				ft_check_integrity(t_list *h);
void				ft_place_coord(t_coord *node, int counter, int i);
void				ft_delete_coord(t_coord *c);
void				coord_helper(char *str, t_coord *temp);
void				ft_place_under_4_helper(char *str, char *map, int start);
int					conn_value(char *s, int i, int conn);

#endif
