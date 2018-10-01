/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:14:48 by allallem          #+#    #+#             */
/*   Updated: 2018/03/14 19:00:50 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_take_name(t_lemin *p, int i, char *str, int link)
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
