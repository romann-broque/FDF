/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:30:01 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/09 16:15:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *nb1, int *nb2)
{
	int	tmp;

	tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

int		get_sign(int nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

int		get_max(const int nb1, const int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	return (nb1);
}
