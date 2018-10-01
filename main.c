/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:25:04 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 07:20:48 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_link(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str[0] == '#')
		return (0);
	while (str[i])
	{
		while (str[i] != '-' && str[i] && str[i] > 32)
			i++;
		if (str[i] == '-')
			j++;
		if (str[i])
			i++;
	}
	if (j == 1)
		return (1);
	return (0);
}

int		ft_nope(char **str)
{
	free(*str);
	return (0);
}

int		main(void)
{
	t_lemin st;
	t_lemin *p;

	p = &st;
	ft_bzero(p, sizeof(t_lemin));
	if (ft_parser(p, NULL, NULL))
	{
		if (!ft_work_on_data(p))
		{
			ft_printf("ERROR\n");
			return (0);
		}
		else if (!ft_go_fourmis(p))
		{
			ft_printf("ERROR\n");
			return (0);
		}
		ft_throw_fourmis(p);
	}
	else
		ft_printf("Usage : cat lem_in-file | ./lem_in\n");
	return (0);
}
