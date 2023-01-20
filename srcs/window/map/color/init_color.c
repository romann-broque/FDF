/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:23:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/20 10:34:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint	sum_color(t_color color)
{
	color.red <<= 16;
	color.green <<= 8;
	return (color.red + color.green + color.blue);
}

void	init_color(t_color *color)
{
	color->red = 0;
	color->green = 0;
	color->blue = UCHAR_MAX;
	color->sum = sum_color(*color);
}
