/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:07:33 by allallem          #+#    #+#             */
/*   Updated: 2018/03/24 04:40:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_visu.h"

int			my_key_event(int key, t_visu *p)
{
	if (key == 124 && p->play != 2)
		p->play = 1;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (1);
}

int			ft_check_link(char *str)
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

int			main(void)
{
	t_visu	*p;
	t_visu	st;

	p = &st;
	ft_bzero(p, sizeof(t_visu));
	if (ft_parser(p))
	{
		ft_work_on_data(p);
		p->mlx = mlx_init();
		p->img = mlx_new_image(p->mlx, 1920, 1080);
		p->data_img = (unsigned char*)mlx_get_data_addr(p->img, &p->bpp,
		&p->size_line, &p->endian);
		p->win = mlx_new_window(p->mlx, 1920, 1080, "lem_in_visu");
		ft_generate_first(p);
		mlx_key_hook(p->win, my_key_event, p);
		mlx_loop_hook(p->mlx, ft_game, p);
		mlx_loop(p->mlx);
	}
	return (0);
}
