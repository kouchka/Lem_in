/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_fourmis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:27:12 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 03:07:53 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_search_start(t_lemin *p)
{
	int i;

	i = 0;
	while (p->room[i]->name)
	{
		if (!ft_strcmp(p->startn, p->room[i]->name))
		{
			if (p->room[i]->distance != 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

static int	ft_recur_way(t_room *p, int i, char *str, char *str2)
{
	int		j;
	t_room	*p2;

	j = 0;
	while (p->link[j])
	{
		p2 = p->link[j];
		if ((p2->distance > i || p2->distance == 0) && ft_strcmp(p2->name, str))
			p2->distance = i;
		j++;
	}
	j = 0;
	while (p->link[j])
	{
		p2 = p->link[j];
		if (ft_strcmp(p2->name, str) && p2->distance > p->distance
		&& ft_strcmp(p2->name, str2))
			ft_recur_way(p->link[j], i + 1, str, str2);
		j++;
	}
	return (1);
}

static int	ft_search_end(t_lemin *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (ft_strcmp(p->room[i]->name, p->endn))
		i++;
	p->room[i]->distance = 0;
	ft_recur_way(p->room[i], 1, p->endn, p->startn);
	return (ft_search_start(p));
}

int			ft_go_fourmis(t_lemin *p)
{
	int i;

	i = 0;
	if (!ft_search_end(p))
		return (0);
	while (p->data[i])
	{
		free(p->data[i]);
		i++;
	}
	free(p->data);
	return (1);
}
