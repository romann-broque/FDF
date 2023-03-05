/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:20:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/03/05 21:06:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_alt_valid(const char *alt)
{
	size_t	i;

	if (*alt == '-' || *alt == '+')
		++alt;
	i = 0;
	while (ft_isdigit(alt[i]) != 0)
		++i;
	return (i > 0 && (alt[i] == '\0' || alt[i] == SEPARATOR));
}

static bool	is_hex_valid(const char *str, const size_t max_size)
{
	size_t	i;

	i = 0;
	while (i < max_size && str[i] != '\0'
		&& ft_strchr(HEX_BASE, str[i]) != NULL)
		++i;
	return (str[i] == '\0');
}

static bool	is_color_valid(const char *color)
{
	bool	ret_val;

	ret_val = false;
	if (color[0] == SEPARATOR)
	{
		++color;
		if (ft_strcmp(color, COLOR_PREFIX) == 0)
		{
			color += ft_strlen(COLOR_PREFIX);
			ret_val = is_hex_valid(color, 6);
		}
	}
	else
		ret_val = true;
	return (ret_val);
}

bool	is_format_valid(const char *str)
{
	return (is_alt_valid(str)
		&& is_color_valid(str + index_of(str, SEPARATOR) + 1));
}

bool	is_color_prefix_valid(const char *format)
{
	return (ft_strncmp(format, COLOR_PREFIX, ft_strlen(COLOR_PREFIX)) == 0);
}
