/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_on_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:49:06 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 03:05:28 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_put_in_room(t_lemin *p, int c, int j)
{
	int i;

	i = 0;
	while (p->data[c][i] != ' ')
		i++;
	p->room[j]->name = ft_strsub(p->data[c], 0, i);
	p->room[j]->x = ft_atoi(p->data[c] + i);
	i++;
	while (p->data[c][i] != ' ')
		i++;
	p->room[j]->y = ft_atoi(p->data[c] + i);
	return (1);
}

static int	ft_assign_room(t_lemin *p)
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

static int	ft_count_room(t_lemin *p)
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

static int	ft_check_start_end(t_lemin *p, char *str)
{
	char	**tmp;

	tmp = NULL;
	p->i = 0;
	while (ft_strcmp(p->data[p->i], str))
		p->i = p->i + 1;
	if (!p->data[p->i + 1] || ft_count_number(p->data[p->i + 1]) != 3)
		return (0);
	tmp = ft_strsplit(p->data[p->i + 1], ' ');
	if (!ft_strcmp(str, "##start"))
		p->startn = ft_strdup(tmp[0]);
	else if (!ft_strcmp(str, "##end"))
		p->endn = ft_strdup(tmp[0]);
	p->i = 0;
	while (tmp[p->i])
	{
		free(tmp[p->i]);
		p->i++;
	}
	free(tmp);
	return (1);
}

int			ft_work_on_data(t_lemin *p)
{
	int i;
	int j;

	i = 0;
	if (p->start == 0 || p->end == 0 || p->fourmis <= 0)
		return (0);
	if (!ft_check_start_end(p, "##start") || !ft_check_start_end(p, "##end"))
		return (0);
	j = ft_count_room(p);
	if (j == 0 || !(p->room = malloc(sizeof(t_room*) * (j + 1))))
		return (0);
	while (j >= 0)
	{
		if (!(p->room[j] = ft_memalloc(sizeof(t_room))))
			return (0);
		j--;
	}
	p->room[ft_count_room(p)]->name = NULL;
	ft_assign_room(p);
	return (ft_get_link(p));
}
