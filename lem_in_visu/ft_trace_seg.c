/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:07:02 by allallem          #+#    #+#             */
/*   Updated: 2018/03/22 15:34:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void		ft_trace_baton(t_visu *p)
{
	int		j;

	j = 0;
	p->ydiff = ft_abs(p->ydiff);
	while (j < p->ydiff)
	{
		ft_put_in_calcu(p, (p->x1 * 4) + (p->size_line * p->y1), p->color);
		p->y1++;
		j++;
	}
}

void		ft_trace_up_left_right(t_visu *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1--;
			yjump = yjump - 1;
		}
		if (i == 0)
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1),
					p->color);
		else if (i == 1)
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1),
					p->color);
		yjump += p->temp;
		j++;
	}
}

void		ft_trace_up_right_left(t_visu *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->xdiff || j < p->ydiff)
	{
		if (yjump >= 1 && i == 0)
		{
			p->x1--;
			yjump -= 1;
		}
		else if (yjump >= 1 && i == 1)
		{
			p->x1++;
			yjump -= 1;
		}
		ft_put_in_calcu(p, (((p->x1 * 4) + ((p->size_line) * p->y1))),
				p->color);
		j++;
		p->y1--;
		yjump += p->temp;
	}
}

void		ft_trace_bottom_left_right(t_visu *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->xdiff || j < p->ydiff)
	{
		if (yjump >= 1 && i == 0)
		{
			p->x1--;
			yjump -= 1;
		}
		else if (yjump >= 1 && i == 1)
		{
			p->x1++;
			yjump -= 1;
		}
		ft_put_in_calcu(p, (((p->x1 * 4) + ((p->size_line) * p->y1))),
			p->color);
		j++;
		p->y1++;
		yjump += p->temp;
	}
}

void		ft_trace_bottom_right_left(t_visu *p, int i)
{
	float	yjump;
	int		j;

	j = 0;
	ft_init_seg(p, &yjump);
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1++;
			yjump = yjump - 1;
		}
		if (i == 1)
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1),
					p->color);
		else if (i == 0)
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1),
					p->color);
		j++;
		yjump += p->temp;
	}
}
