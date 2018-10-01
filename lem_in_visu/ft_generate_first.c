/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:42:54 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 04:39:12 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void		ft_put_in_calcu(t_visu *p, int x, int color)
{
	if (x < 0 || x > p->winx * p->winy * 4 ||
	!(x >= p->size_line * p->y1 && x < p->size_line * (p->y1 + 1)))
		return ;
	p->data_img[x] = color & 0xFF;
	p->data_img[x + 1] = (color >> 8) & 0xFF;
	p->data_img[x + 2] = (color >> 16) & 0xFF;
}

void		ft_redirect(t_visu *p)
{
	if (p->xdiff > 0 && p->ydiff >= 0 && p->xdiff >= p->ydiff)
		ft_trace_up_left_right(p, 1);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left(p, 1);
	else if (p->xdiff < 0 && p->ydiff >= 0 && ft_abs(p->xdiff) >= p->ydiff)
		ft_trace_up_left_right(p, 0);
	else if (p->xdiff < 0 && p->ydiff < 0
			&& ft_abs(p->xdiff) >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left(p, 0);
	else if (p->xdiff < 0 && p->ydiff < 0
			&& ft_abs(p->xdiff) <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right(p, 0);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right(p, 1);
	else if (p->xdiff < 0 && p->ydiff > 0 && ft_abs(p->xdiff) <= p->ydiff)
		ft_trace_up_right_left(p, 0);
	else if (p->xdiff >= 0 && p->ydiff > 0 && p->xdiff <= p->ydiff)
		ft_trace_up_right_left(p, 1);
	else if (p->xdiff == 0 && (p->ydiff < 0 || p->ydiff > 0))
		ft_trace_baton(p);
}

static void	ft_assign(t_visu *p, int i, int j)
{
	p->x1 = p->room[i]->x * p->xmap;
	p->y1 = p->room[i]->y * p->ymap;
	p->x2 = p->room[i]->link[j]->x * p->xmap;
	p->y2 = p->room[i]->link[j]->y * p->ymap;
	p->xdiff = p->x2 - p->x1;
	p->ydiff = p->y1 - p->y2;
	ft_redirect(p);
}

static void	ft_assign_x_y(t_visu *p)
{
	int		i;

	i = 0;
	p->color = 0xFFFFFF;
	p->xmap = 0;
	p->ymap = 0;
	while (p->room[i])
	{
		if (p->room[i]->x > p->xmap)
			p->xmap = p->room[i]->x;
		if (p->room[i]->y > p->ymap)
			p->ymap = p->room[i]->y;
		i++;
	}
	p->xmap = p->xmap + p->xmap / 3;
	p->ymap = p->ymap + p->ymap / 3;
	p->xmap = 1920 / p->xmap;
	p->ymap = 1080 / p->ymap;
}

void		ft_generate_first(t_visu *p)
{
	int i;
	int j;

	i = 0;
	p->winx = 1920;
	p->winy = 1080;
	ft_assign_x_y(p);
	j = 0;
	while (p->room[i])
	{
		j = 0;
		ft_put_circle(p, i, 0, 0);
		while (p->room[i]->link[j])
		{
			ft_assign(p, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
