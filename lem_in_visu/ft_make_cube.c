/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 05:51:41 by allallem          #+#    #+#             */
/*   Updated: 2018/03/23 22:13:58 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void		ft_make_cube(t_visu *p, int x)
{
	int		y;
	int		x2;

	y = -p->size_line * 6;
	while (x + y < x + (p->size_line * 6))
	{
		x2 = -24;
		while (x + x2 <= x + 24)
		{
			ft_put_in_calcu_spe(p, x + x2 + y, 0xFF0000);
			x2 += 4;
		}
		y += p->size_line;
	}
}
