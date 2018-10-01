/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 00:11:45 by allallem          #+#    #+#             */
/*   Updated: 2018/03/23 22:55:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

int			ft_game(t_visu *p)
{
	if (p->play == 1)
		ft_go_fm(p);
	else if (p->play == 2)
		ft_trace_fm(p);
	return (1);
}