/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:11:21 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 03:53:27 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VISU_H
# define LEM_IN_VISU_H

# include "minilibx_macos/mlx.h"
# include "../libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				fm;
	int				nblink;
	struct s_room	**link;
	int				*nbr;
	float			*temp;
	float			*yjump;
	int				*j;
	int				*x1;
	int				*y1;
	int				mv;
	struct s_room	**start;
}					t_room;

typedef struct		s_visu
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data_img;
	int				endian;
	int				bpp;
	int				size_line;
	int				xmap;
	int				ymap;
	int				y1;
	int				y2;
	int				x1;
	int				x2;
	int				winx;
	int				winy;
	int				xdiff;
	int				ydiff;
	int				play;
	float			temp;
	int				color;
	char			**data;
	char			**dpl;
	t_room			**room;
	t_room			*startn;
	t_room			*endn;
}					t_visu;

int					ft_parser(t_visu *p);
int					ft_check_link(char *str);
int					ft_work_on_data(t_visu *p);
void				ft_take_name(t_visu *p, int i, char *str, int link);
int					ft_get_link(t_visu *p);
void				ft_put_in_calcu(t_visu *p, int x, int color);
void				ft_trace_up_left_right(t_visu *p, int i);
void				ft_trace_up_right_left(t_visu *p, int i);
void				ft_trace_bottom_left_right(t_visu *p, int i);
void				ft_trace_bottom_right_left(t_visu *p, int i);
void				ft_trace_baton(t_visu *p);
void				ft_generate_first(t_visu *p);
void				ft_init_seg(t_visu *p, float *yjump);
void				ft_put_circle(t_visu *p, int i, int x, int y);
int					ft_game(t_visu *p);
void				ft_go_fm(t_visu *p);
void				ft_trace_up_right_left_fm(t_visu *p, int i, int j, int k);
void				ft_trace_up_left_right_fm(t_visu *p, int i, int j, int k);
void				ft_trace_bottom_right_left_fm(t_visu *p, int i, int j,
				int k);
void				ft_trace_bottom_left_right_fm(t_visu *p, int i, int j,
				int k);
void				ft_trace_fm(t_visu *p);
void				ft_put_in_calcu_spe(t_visu *p, int x, int color);
void				ft_make_cube(t_visu *p, int x);
void				ft_trace_up_lr(t_visu *p, int i, int j, int k);
void				ft_trace_bottom_rl(t_visu *p, int i, int j, int k);
void				ft_reset_data(t_visu *p);
int					ft_hardmalloc(t_visu *p, int i);
int					ft_while_str(char *str, int i);

#endif
