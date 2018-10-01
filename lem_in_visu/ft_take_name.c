/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:15:33 by allallem          #+#    #+#             */
/*   Updated: 2018/03/23 01:16:30 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

void		ft_init_seg(t_visu *p, float *yjump)
{
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff >= p->ydiff) ? *yjump = (float)p->ydiff / (float)p->xdiff : 0;
	(p->ydiff >= p->xdiff) ? *yjump = (float)p->xdiff / (float)p->ydiff : 0;
	p->temp = *yjump;
}

void		ft_take_name(t_visu *p, int i, char *str, int link)
{
	int j;
	int k;
	int l;

	k = 0;
	j = 0;
	while (str[j] == p->room[i]->name[j])
		j++;
	if (str[j] == '-' && p->room[i]->name[j] == '\0')
		j++;
	else
		j = 0;
	while (p->room[k]->name)
	{
		l = 0;
		while (str[j + l] && str[j + l] == p->room[k]->name[l])
			l++;
		if (l > 0 && !ft_strequ(p->room[i]->name,
			p->room[k]->name) && (str[j + l] == '\0' || str[j + l] == '-'))
		{
			p->room[i]->link[link] = p->room[k];
			return ;
		}
		k++;
	}
}
