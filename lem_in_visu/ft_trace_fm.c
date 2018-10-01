/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_fm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 03:19:00 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:45:55 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void			ft_put_in_calcu_spe(t_visu *p, int x, int color)
{
	p->data_img[x] = color & 0xFF;
	p->data_img[x + 1] = (color >> 8) & 0xFF;
	p->data_img[x + 2] = (color >> 16) & 0xFF;
}

static void		ft_redirect(t_visu *p, int i, int j)
{
	if (p->room[i]->nbr[j] == 1)
		ft_make_cube(p, ((p->room[i]->x * p->xmap) * 4 + (p->room[i]->y
						* p->ymap) * p->size_line));
	else if (p->xdiff > 0 && p->ydiff >= 0 && p->xdiff >= p->ydiff)
		ft_trace_up_left_right_fm(p, 1, i, j);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left_fm(p, 1, i, j);
	else if (p->xdiff < 0 && p->ydiff >= 0 && ft_abs(p->xdiff) >= p->ydiff)
		ft_trace_up_left_right_fm(p, 0, i, j);
	else if (p->xdiff < 0 && p->ydiff < 0
			&& ft_abs(p->xdiff) >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left_fm(p, 0, i, j);
	else if (p->xdiff < 0 && p->ydiff < 0
			&& ft_abs(p->xdiff) <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right_fm(p, 0, i, j);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right_fm(p, 1, i, j);
	else if (p->xdiff < 0 && p->ydiff > 0 && ft_abs(p->xdiff) <= p->ydiff)
		ft_trace_up_right_left_fm(p, 0, i, j);
	else if (p->xdiff >= 0 && p->ydiff > 0 && p->xdiff <= p->ydiff)
		ft_trace_up_right_left_fm(p, 1, i, j);
}

static void		ft_assign(t_visu *p, int i, int j)
{
	p->x1 = p->room[i]->start[j]->x * p->xmap;
	p->y1 = p->room[i]->start[j]->y * p->ymap;
	p->x2 = p->room[i]->x * p->xmap;
	p->y2 = p->room[i]->y * p->ymap;
	p->xdiff = p->x2 - p->x1;
	p->ydiff = p->y1 - p->y2;
	ft_redirect(p, i, j);
}

void			ft_swap_play(t_visu *p)
{
	int i;
	int j;

	i = 0;
	while (p->room[i])
	{
		j = 0;
		while (j < p->room[i]->mv)
		{
			if (p->room[i]->mv > 0 && p->room[i]->nbr[j] == 0)
				return ;
			j++;
		}
		i++;
	}
	ft_reset_data(p);
	p->play = 1;
}

void			ft_trace_fm(t_visu *p)
{
	int i;
	int j;

	i = 0;
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, p->winx, p->winy);
	p->data_img = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp,
			&p->size_line, &p->endian);
	ft_generate_first(p);
	while (p->room[i])
	{
		if (p->room[i]->mv > 0)
		{
			j = 0;
			while (j < p->room[i]->mv)
			{
				ft_assign(p, i, j);
				j++;
			}
		}
		i++;
	}
	ft_swap_play(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
