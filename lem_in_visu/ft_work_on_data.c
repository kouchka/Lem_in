/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_on_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:38:54 by allallem          #+#    #+#             */
/*   Updated: 2018/03/23 23:03:59 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

static int	ft_put_in_room(t_visu *p, int c, int j)
{
	int i;
	int k;

	k = 1;
	i = 0;
	while (p->data[c][i] != ' ')
		i++;
	p->room[j]->name = ft_strsub(p->data[c], 0, i);
	p->room[j]->x = ft_atoi(p->data[c] + i) + 1;
	i++;
	while (p->data[c][i] != ' ')
		i++;
	p->room[j]->y = ft_atoi(p->data[c] + i) + 1;
	while (c - k > 0 && (p->startn == NULL || p->endn == NULL) && p->data[c - k]
	[0] == '#' && (ft_strcmp(p->data[c - k],
	"##start") && ft_strcmp(p->data[c - k], "##end")))
		k++;
	if (c > k && !ft_strcmp(p->data[c - k], "##start"))
		p->startn = p->room[j];
	else if (c > k && !ft_strcmp(p->data[c - k], "##end"))
		p->endn = p->room[j];
	return (1);
}

static int	ft_assign_room(t_visu *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (p->data[i])
	{
		if (ft_count_number(p->data[i]) == 3)
		{
			if (!ft_put_in_room(p, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_count_room(t_visu *p)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (p->data[i])
	{
		if (ft_count_number(p->data[i]) == 3)
			count++;
		i++;
	}
	return (count);
}

int			ft_work_on_data(t_visu *p)
{
	int i;
	int j;

	i = 0;
	j = ft_count_room(p);
	if (!(p->room = malloc(sizeof(t_room*) * (j + 1))))
		return (0);
	p->room[j] = NULL;
	j--;
	while (j >= 0)
	{
		if (!(p->room[j] = ft_memalloc(sizeof(t_room))))
			return (0);
		j--;
	}
	ft_assign_room(p);
	ft_get_link(p);
	return (1);
}
