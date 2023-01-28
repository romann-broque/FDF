/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:19:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_H

// altitude.c

void	altitude(const t_map *map);

// zoom.c

void	zoom(const t_map *map);

// center.c

void	center(t_map *map, const int x_offset, const int y_offset);

// offset.c

void	offset(t_map *map, const float x_offset, const float y_offset);

// rotate.c

void	rotate(t_map *map);

// transform_map.c

void	transform_map(t_map *map);

#endif
