/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:39:04 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 01:20:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size_nb(int nb)
{
	size_t	size;

	size = (nb == 0);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

static unsigned long	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	cp_nb(char *dest, int n, size_t len)
{
	size_t			i;
	unsigned int	abs_n;

	abs_n = get_abs(n);
	i = 0;
	while (i < len)
	{
		dest[len - i - 1] = (abs_n % 10) + '0';
		abs_n /= 10;
		++i;
	}
	dest[len] = '\0';
}

char	*ft_itoa(int n)
{
	const size_t	len = get_size_nb(n);
	const bool		is_neg = (n < 0);
	char			*new;

	new = (char *)malloc((len + is_neg + 1) * sizeof(char));
	if (new != NULL)
	{
		if (n < 0)
			new[0] = '-';
		cp_nb(new + is_neg, n, len);
	}
	return (new);
}
