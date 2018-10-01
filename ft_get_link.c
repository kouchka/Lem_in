/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:38:45 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:07:53 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_number(t_lemin *p, int j)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (p->room[i]->name)
	{
		if ((!ft_strcmp(p->room[i]->name, p->startn) && p->room[i]->nblink == 0)
	|| ((!ft_strcmp(p->room[i]->name, p->endn) && p->room[i]->nblink == 0)))
			return (0);
		i++;
	}
	i = 0;
	while (p->room[i]->name)
	{
		k = k + p->room[i]->nblink;
		i++;
	}
	if (k != j * 2 || k == 0 || j == 0)
		return (0);
	return (1);
}

static int	ft_find_name(t_lemin *p, char *str, int i)
{
	int k;
	int j;
	int limit;
	int size_name;

	size_name = ft_strlen(p->room[i]->name);
	limit = ft_strlen(str);
	j = 0;
	k = 0;
	while (str[j] && str[j] == p->room[i]->name[j])
		j++;
	if (j == size_name && (str[j + k] == '\0' || str[j + k] == '-'))
		return (1);
	while (str[j] && str[j] != '-')
		j++;
	j++;
	while (str[j + k] && str[j + k] == p->room[i]->name[k])
		k++;
	if (k == size_name && (str[j + k] == '\0' || str[j + k] == '-'))
		return (1);
	return (0);
}

static void	ft_make_link(t_lemin *p, int i)
{
	int j;
	int link;

	link = 0;
	j = 0;
	while (p->data[j])
	{
		if (ft_check_link(p->data[j]) && ft_find_name(p, p->data[j], i))
		{
			ft_take_name(p, i, p->data[j], link);
			link++;
		}
		j++;
	}
}

static int	ft_save_link(t_lemin *p, int i)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (p->data[j])
	{
		if (ft_check_link(p->data[j]) && ft_find_name(p, p->data[j], i))
			count++;
		j++;
	}
	p->room[i]->nblink = count;
	if (count == 0 || !(p->room[i]->link = ft_memalloc(sizeof(t_room*)
		* (count + 1))))
		return (0);
	j = 0;
	while (j < count)
	{
		p->room[i]->link[j] = NULL;
		j++;
	}
	if (count == 0)
		return (0);
	return (1);
}

int			ft_get_link(t_lemin *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (p->room[i]->name)
	{
		if (ft_save_link(p, i))
			ft_make_link(p, i);
		i++;
	}
	i = 0;
	while (p->data[i])
	{
		if (ft_check_link(p->data[i]))
			j++;
		i++;
	}
	return (ft_check_number(p, j));
}
