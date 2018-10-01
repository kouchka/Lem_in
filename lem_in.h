/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:19:58 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:50:06 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				nblink;
	struct s_room	**link;
	int				distance;
	int				nbr;
	int				mv;
	int				path;
}					t_room;

typedef struct		s_lemin
{
	int		i;
	int		f;
	char	*startn;
	char	*endn;
	char	**data;
	int		start;
	int		end;
	int		fourmis;
	int		landed;
	t_room	**room;
}					t_lemin;

int					ft_parser(t_lemin *p, char *dr_freeman, char *tmp);
int					ft_work_on_data(t_lemin *p);
int					ft_nope(char **str);
int					ft_check_link(char *str);
int					ft_get_link(t_lemin *p);
void				ft_take_name(t_lemin *p, int i, char *str, int link);
int					ft_go_fourmis(t_lemin *p);
void				ft_look_for_next_room(t_room *p, t_lemin *p2, t_room *end);
void				ft_throw_fourmis(t_lemin*p);
void				ft_land_from_start(t_room *p, t_lemin *point, t_room *end);
void				ft_throw_all(t_lemin *p, t_room *end);

#endif
