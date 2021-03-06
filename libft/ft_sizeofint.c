/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:26:20 by allallem          #+#    #+#             */
/*   Updated: 2018/02/06 00:27:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sizeofint(int size)
{
	int i;

	i = 0;
	while (size > 9 || size < -9)
	{
		size = size / 10;
		i++;
	}
	i++;
	return (i);
}
