/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/16 16:57:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_map(t_map *map)
{
	zoom(map);
	center(map, WIDTH / 2, HEIGHT / 2);
	rotate(map);
	altitude(map);
}
