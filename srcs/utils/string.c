/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:36:24 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/12 18:19:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	strcountchr(const char *str, const char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		count += (str[i] == c);
		++i;
	}
	return (count);
}

size_t	get_array_size_char(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		++size;
	return (size);
}
