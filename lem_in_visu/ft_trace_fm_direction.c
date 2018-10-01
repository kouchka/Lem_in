/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_fm_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 04:09:02 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 03:40:30 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void	ft_init_seg_spe(t_visu *p, int i, int k)
{
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff >= p->ydiff) ? p->room[i]->yjump[k] = (float)p->ydiff
		/ (float)p->xdiff : 0;
	(p->ydiff >= p->xdiff) ? p->room[i]->yjump[k] = (float)p->xdiff
		/ (float)p->ydiff : 0;
	p->room[i]->temp[k] = p->room[i]->yjump[k];
	p->room[i]->x1[k] = p->x1;
	p->room[i]->y1[k] = p->y1;
}

void	ft_trace_up_left_right_fm(t_visu *p, int i, int j, int k)
{
	if (p->room[j]->temp[k] == 0.0)
		ft_init_seg_spe(p, j, k);
	if (p->room[j]->yjump[k] >= 1)
	{
		p->room[j]->y1[k]--;
		p->room[j]->yjump[k] -= 1;
	}
	ft_trace_up_lr(p, i, j, k);
	p->room[j]->yjump[k] += p->room[j]->temp[k];
	p->room[j]->j[k]++;
}

void	ft_trace_up_right_left_fm(t_visu *p, int i, int j, int k)
{
	if (p->room[j]->temp[k] == 0.0)
		ft_init_seg_spe(p, j, k);
	if (p->room[j]->yjump[k] >= 1 && i == 0)
	{
		p->room[j]->x1[k]--;
		p->room[j]->yjump[k] -= 1;
	}
	else if (p->room[j]->yjump[k] >= 1 && i == 1)
	{
		p->room[j]->x1[k]++;
		p->room[j]->yjump[k] -= 1;
	}
	ft_make_cube(p, (((p->room[j]->x1[k] * 4) + ((p->size_line)
				* p->room[j]->y1[k]))));
	if (((p->room[j]->x1[k] * 4) + ((p->size_line) * p->room[j]->y1[k])) ==
	((p->room[j]->x * p->xmap) * 4) + (p->room[j]->y * p->ymap) * p->size_line)
		p->room[j]->nbr[k] = 1;
	p->room[j]->j[k]++;
	p->room[j]->y1[k]--;
	p->room[j]->yjump[k] += p->room[j]->temp[k];
}

void	ft_trace_bottom_left_right_fm(t_visu *p, int i, int j, int k)
{
	if (p->room[j]->temp[k] == 0.0)
		ft_init_seg_spe(p, j, k);
	if (p->room[j]->yjump[k] >= 1 && i == 0)
	{
		p->room[j]->x1[k]--;
		p->room[j]->yjump[k] -= 1;
	}
	else if (p->room[j]->yjump[k] >= 1 && i == 1)
	{
		p->room[j]->x1[k]++;
		p->room[j]->yjump[k] -= 1;
	}
	ft_make_cube(p, (p->room[j]->x1[k] * 4) + ((p->size_line) *
		p->room[j]->y1[k]));
	if (((p->room[j]->x1[k] * 4) + ((p->size_line) * p->room[j]->y1[k])) ==
((p->room[j]->x * p->xmap) * 4) + (p->room[j]->y * p->ymap) * p->size_line)
		p->room[j]->nbr[k] = 1;
	p->room[j]->j[k]++;
	p->room[j]->y1[k]++;
	p->room[j]->yjump[k] += p->room[j]->temp[k];
}

void	ft_trace_bottom_right_left_fm(t_visu *p, int i, int j, int k)
{
	if (p->room[j]->temp[k] == 0.0)
		ft_init_seg_spe(p, j, k);
	if (p->room[j]->yjump[k] >= 1)
	{
		p->room[j]->y1[k]++;
		p->room[j]->yjump[k] -= 1;
	}
	ft_trace_bottom_rl(p, i, j, k);
	p->room[j]->j[k]++;
	p->room[j]->yjump[k] += p->room[j]->temp[k];
}
