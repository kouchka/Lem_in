/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:26:52 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 03:41:01 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void		ft_put_circle(t_visu *p, int i, int x, int y)
{
	int		cmpt;
	int		cmpt2;

	cmpt = -p->xmap / 4;
	x = p->room[i]->x * p->xmap;
	y = p->room[i]->y * p->ymap;
	while (y + cmpt < (y + (p->xmap / 4)))
	{
		p->y1 = y + cmpt;
		cmpt2 = -p->xmap / 4;
		while (x + cmpt2 < (x + (p->xmap / 4)))
		{
			if (p->room[i] == p->startn)
				ft_put_in_calcu(p, ((x + cmpt2) * 4) + ((y + cmpt) *
				p->size_line), 0x00FF00);
			else if (p->room[i] == p->endn)
				ft_put_in_calcu(p, ((x + cmpt2) * 4) + ((y + cmpt) *
				p->size_line), 0xFF0000);
			else
				ft_put_in_calcu(p, ((x + cmpt2) * 4) + ((y + cmpt) *
				p->size_line), p->color);
			cmpt2++;
		}
		cmpt++;
	}
}
