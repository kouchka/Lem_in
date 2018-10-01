/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_foumis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:23:33 by allallem          #+#    #+#             */
/*   Updated: 2018/03/23 23:57:47 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*ft_search(t_lemin *p, char *str)
{
	int i;

	i = 0;
	while (p->room[i]->name && ft_strcmp(p->room[i]->name, str))
		i++;
	return (p->room[i]);
}

static void		ft_reset_mv(t_lemin *p)
{
	int i;

	i = 0;
	while (p->room[i]->name)
	{
		p->room[i]->mv = 0;
		i++;
	}
}

static int		ft_check_way(t_lemin *p, int fm, t_room *end)
{
	int		i;
	int		j;
	t_room	*start;
	t_room	*p2;

	j = 0;
	i = 0;
	start = ft_search(p, p->startn);
	while (start->link[i])
	{
		p2 = start->link[i];
		if (p2 == end)
		{
			ft_throw_all(p, end);
			return (0);
		}
		else if (fm > j)
		{
			p2->path = 1;
			j = j + p2->distance;
		}
		i++;
	}
	return (1);
}

static void		ft_goooo(t_lemin *p, t_room *end)
{
	int		i;
	t_room	*start;

	i = 0;
	while (p->room[i]->name)
	{
		if (p->room[i]->nbr > 0 && p->room[i]->mv == 0 && ft_strcmp(p->startn,
	p->room[i]->name) && ft_strcmp(p->endn, p->room[i]->name))
			ft_look_for_next_room(p->room[i], p, end);
		i++;
	}
	start = ft_search(p, p->startn);
	ft_land_from_start(start, p, end);
}

void			ft_throw_fourmis(t_lemin *p)
{
	t_room	*end;

	p->landed = p->fourmis;
	end = ft_search(p, p->endn);
	while (end->nbr < p->fourmis)
	{
		if (!ft_check_way(p, p->landed, end))
			return ;
		ft_goooo(p, end);
		ft_reset_mv(p);
		ft_printf("\n");
	}
}
