/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_fm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 00:18:01 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:48:17 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

static void	ft_get_start_end(char *str, t_room **start, t_room **end, t_visu *p)
{
	int i;
	int j;
	int fm;

	j = 0;
	i = 1;
	fm = ft_atoi(str + i);
	i = 0;
	while (p->room[i] && p->room[i]->fm != fm)
		i++;
	if (p->room[i] && p->room[i]->fm == fm)
	{
		p->room[i]->fm = 0;
		*start = p->room[i];
	}
	else
		*start = p->startn;
	i = ft_while_str(str, i);
	while (p->room[j] && ft_strcmp(p->room[j]->name, str + i))
		j++;
	if (!p->room[j])
		exit(EXIT_SUCCESS);
	p->room[j]->fm = fm;
	*end = p->room[j];
}

static void	ft_check_if_ok(char *str)
{
	int		i;

	i = 0;
	if (!str[i] || str[i] != 'L')
		exit(EXIT_SUCCESS);
	else
		i++;
	while (!str[i] || (str[i] >= 48 && str[i] <= 57))
		i++;
	if (!str[i] || str[i] != '-')
		exit(EXIT_SUCCESS);
	else
		i++;
}

static void	ft_reassign_start(t_visu *p, t_room *start, t_room *end)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (p->room[i])
	{
		j = 0;
		while (p->dpl[j] && p->room[i]->mv > 0)
		{
			k = 0;
			ft_get_start_end(p->dpl[j], &start, &end, p);
			while (k < end->mv && end->start[k])
				k++;
			(k < end->mv) ? end->start[k] = start : 0;
			j++;
		}
		i++;
	}
}

static void	ft_work_on_tab(t_visu *p)
{
	int i;
	int j;
	int k;

	i = 0;
	while (p->room[i])
	{
		j = 0;
		while (p->dpl[j])
		{
			k = 0;
			while (p->dpl[j][k] != '-')
				k++;
			if (p->dpl[j][k] == '-')
				k++;
			if (!ft_strcmp(p->dpl[j] + k, p->room[i]->name))
				p->room[i]->mv += 1;
			j++;
		}
		if (!ft_hardmalloc(p, i))
			exit(EXIT_SUCCESS);
		i++;
	}
	ft_reassign_start(p, NULL, NULL);
}

void		ft_go_fm(t_visu *p)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (get_next_line(0, &str) <= 0)
		return ;
	p->dpl = ft_strsplit(str, ' ');
	free(str);
	while (p->dpl[i])
	{
		ft_check_if_ok(p->dpl[i]);
		i++;
	}
	p->play = 2;
	ft_work_on_tab(p);
	i = 0;
	while (p->dpl[i])
	{
		free(p->dpl[i]);
		i++;
	}
	free(p->dpl);
}
