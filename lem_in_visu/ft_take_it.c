/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:20:33 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:44:12 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

int				ft_while_str(char *str, int i)
{
	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	i++;
	return (i);
}

int				ft_hardmalloc(t_visu *p, int i)
{
	if (p->room[i]->mv > 0 && (!(p->room[i]->start =
ft_memalloc(sizeof(t_room*) * (p->room[i]->mv + 1))) || !(p->room[i]->temp =
ft_memalloc(sizeof(float) * (p->room[i]->mv))) || !(p->room[i]->yjump =
ft_memalloc(sizeof(float) * (p->room[i]->mv))) || !(p->room[i]->j =
ft_memalloc(sizeof(int) * (p->room[i]->mv))) || !(p->room[i]->x1 =
ft_memalloc(sizeof(int) * (p->room[i]->mv))) || !(p->room[i]->y1 =
ft_memalloc(sizeof(int) * (p->room[i]->mv))) || !(p->room[i]->nbr =
ft_memalloc(sizeof(int) * (p->room[i]->mv)))))
		return (0);
	return (1);
}

void			ft_trace_up_lr(t_visu *p, int i, int j, int k)
{
	if (i == 0)
	{
		ft_make_cube(p, ((p->room[j]->x1[k] - p->room[j]->j[k]) * 4) +
				(p->size_line * p->room[j]->y1[k]));
		if (((p->room[j]->x1[k] - p->room[j]->j[k]) * 4) + (p->size_line *
		p->room[j]->y1[k]) == ((p->room[j]->x * p->xmap) * 4) + (p->room[j]->y
						* p->ymap) * p->size_line)
			p->room[j]->nbr[k] = 1;
	}
	else if (i == 1)
	{
		ft_make_cube(p, ((p->room[j]->x1[k] + p->room[j]->j[k]) * 4) +
				(p->size_line * p->room[j]->y1[k]));
		if (((p->room[j]->x1[k] + p->room[j]->j[k]) * 4) + (p->size_line *
					p->room[j]->y1[k]) == ((p->room[j]->x * p->xmap) * 4) +
				(p->room[j]->y * p->ymap) * p->size_line)
			p->room[j]->nbr[k] = 1;
	}
}

void			ft_trace_bottom_rl(t_visu *p, int i, int j, int k)
{
	if (i == 1)
	{
		ft_make_cube(p, ((p->room[j]->x1[k] + p->room[j]->j[k]) * 4) +
				(p->size_line * p->room[j]->y1[k]));
		if (((p->room[j]->x1[k] + p->room[j]->j[k]) * 4) + (p->size_line *
		p->room[j]->y1[k]) == ((p->room[j]->x * p->xmap) * 4) + (p->room[j]->y
						* p->ymap) * p->size_line)
			p->room[j]->nbr[k] = 1;
	}
	else if (i == 0)
	{
		ft_make_cube(p, ((p->room[j]->x1[k] - p->room[j]->j[k]) * 4) +
				(p->size_line * p->room[j]->y1[k]));
		if (((p->room[j]->x1[k] - p->room[j]->j[k]) * 4) + (p->size_line *
		p->room[j]->y1[k]) == ((p->room[j]->x * p->xmap) * 4) + (p->room[j]->y
						* p->ymap) * p->size_line)
			p->room[j]->nbr[k] = 1;
	}
}

void			ft_reset_data(t_visu *p)
{
	int i;

	i = 0;
	while (p->room[i])
	{
		if (p->room[i]->mv > 0)
		{
			free(p->room[i]->start);
			free(p->room[i]->temp);
			free(p->room[i]->yjump);
			free(p->room[i]->x1);
			free(p->room[i]->y1);
			free(p->room[i]->j);
			free(p->room[i]->nbr);
			p->room[i]->start = NULL;
			p->room[i]->nbr = NULL;
			p->room[i]->yjump = NULL;
			p->room[i]->x1 = NULL;
			p->room[i]->y1 = NULL;
			p->room[i]->temp = NULL;
			p->room[i]->j = NULL;
			p->room[i]->mv = 0;
		}
		i++;
	}
}
