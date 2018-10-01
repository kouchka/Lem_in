/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_for_next_room.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:36:07 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 07:18:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_throw_all(t_lemin *p, t_room *end)
{
	while (end->nbr < p->fourmis)
	{
		ft_printf("L%i-%s ", p->landed, end->name);
		p->landed--;
		end->nbr++;
	}
	ft_printf("\n");
}

void		ft_land_from_start(t_room *p, t_lemin *point, t_room *end)
{
	int		i;

	i = 0;
	while (p->link[i] && point->landed > 0)
	{
		if (p->link[i]->path == 1 && p->link[i]->nbr == 0)
		{
			ft_printf("L%i-%s ", point->landed, p->link[i]->name);
			if (p->link[i] != end)
				p->link[i]->mv = 1;
			p->link[i]->nbr = point->landed;
			point->landed--;
		}
		p->link[i]->path = 0;
		i++;
	}
}

static void	ft_look_further(t_room *p3, t_room *p, t_room *end)
{
	if (p->nbr > 0)
	{
		if (end != p3)
		{
			ft_printf("L%i-%s ", p->nbr, p3->name);
			p3->nbr = p->nbr;
			p3->mv = 1;
			p->nbr = 0;
			p->mv = 0;
		}
		else
		{
			ft_printf("L%i-%s ", p->nbr, p3->name);
			p3->nbr++;
			p->nbr = 0;
			p->mv = 0;
		}
	}
}

void		ft_look_for_next_room(t_room *p, t_lemin *point, t_room *end)
{
	int		i;
	int		j;
	t_room	*p2;
	t_room	*p3;

	p2 = NULL;
	p3 = NULL;
	j = 20000;
	i = 0;
	while (p->link[i])
	{
		p2 = p->link[i];
		if (p2 == end)
			ft_look_further(p2, p, end);
		else if (j > p2->distance && ft_strcmp(p2->name, point->startn))
		{
			j = p2->distance;
			p3 = p2;
		}
		i++;
	}
	if (p3 && p3->nbr > 0 && p3->mv == 0 && ft_strcmp(p3->name, point->startn))
		ft_look_for_next_room(p3, point, end);
	if (p3 && p3->nbr == 0 && p->mv == 0 && ft_strcmp(p3->name, point->startn))
		ft_look_further(p3, p, end);
}
