/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:31:59 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 07:38:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

static int		ft_complete_two(t_visu *p, char **tmp, char **keep)
{
	if (*tmp)
		free(*tmp);
	if (*keep == NULL)
		return (0);
	p->data = ft_strsplit(*keep, '\n');
	free(*keep);
	return (1);
}

static void		ft_complete(char **dr_freeman, char **keep, char **tmp)
{
	*dr_freeman = *keep;
	*keep = ft_strjoin(*keep, *tmp);
	free(*dr_freeman);
}

int				ft_parser(t_visu *p)
{
	char	*keep;
	char	*tmp;
	char	*dr_freeman;

	dr_freeman = NULL;
	keep = NULL;
	tmp = NULL;
	while (get_next_line(0, &tmp) > 0 && tmp[0] != '\0')
	{
		if (!ft_strcmp(tmp, "ERROR") || !ft_strncmp(tmp, "usage:", 5))
			exit(EXIT_SUCCESS);
		dr_freeman = tmp;
		tmp = ft_strjoin(tmp, "\n");
		free(dr_freeman);
		if (keep == NULL)
			keep = ft_strdup(tmp);
		else
			ft_complete(&dr_freeman, &keep, &tmp);
		free(tmp);
	}
	return (ft_complete_two(p, &tmp, &keep));
}
