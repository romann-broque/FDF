/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:20:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 16:22:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_color_prefix_valid(const char *format)
{
	return (ft_strncmp(format, COLOR_PREFIX, ft_strlen(COLOR_PREFIX)) == 0);
}
