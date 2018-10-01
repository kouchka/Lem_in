/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:27:18 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 06:49:50 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_finish_check(char *str, int i, int nbr)
{
	while (str[i])
	{
		if (((str[i] < 48 && str[i] > 32) || str[i] > 57) && str[i] != '-')
			return (0);
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-')
		{
			if (str[i] == '-')
				i++;
			while (str[i] >= 48 && str[i] <= 57)
				i++;
			nbr++;
		}
		else
			i++;
	}
	if (nbr == 3)
		return (1);
	return (0);
}

static int		ft_check_format(char *str)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	if (str[0] == 'L')
		return (0);
	if (str[i] != ' ' && str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		if (str[i] == ' ')
			i++;
		nbr++;
	}
	return (ft_finish_check(str, i, nbr));
}

static int		ft_check_line(char *str, t_lemin *p, int i)
{
	static int	fm;

	if (ft_strlen(str) < 1 || p->end > 1 || p->start > 1)
		return (0);
	else if (ft_check_link(str) ||
		(str[0] != '#' && fm == 0 && ft_count_number(str) == 1 && i == 0))
	{
		if (!ft_check_link(str))
			p->fourmis = ft_atoi(str);
		return (1);
	}
	if (str[0] == '#')
	{
		if (ft_strcmp(str, "##start") && ft_strcmp(str, "##end"))
			return (2);
		(!ft_strcmp(str, "##start")) ? p->start += 1 : 0;
		(!ft_strcmp(str, "##end")) ? p->end += 1 : 0;
		return (1);
	}
	return (ft_check_format(str));
}

static void		ft_add_data(char *dr_freeman, char **tmp, char **keep)
{
	dr_freeman = *tmp;
	*tmp = ft_strjoin(*tmp, "\n");
	free(dr_freeman);
	dr_freeman = *keep;
	if (*keep == NULL)
		*keep = ft_strdup(*tmp);
	else
		*keep = ft_strjoin(*keep, *tmp);
	free(dr_freeman);
	free(*tmp);
}

int				ft_parser(t_lemin *p, char *dr_freeman, char *tmp)
{
	char	*keep;
	int		i;
	int		j;

	i = 0;
	keep = NULL;
	while (get_next_line(0, &tmp) > 0 && (j = ft_check_line(tmp, p, i)))
	{
		ft_printf("%s\n", tmp);
		if (j != 2)
		{
			i++;
			ft_add_data(dr_freeman, &tmp, &keep);
		}
		else if (j == 2)
			free(tmp);
	}
	if (j == 0)
		ft_nope(&tmp);
	if (keep == NULL)
		return (0);
	p->data = ft_strsplit(keep, '\n');
	free(keep);
	return (1);
}
