/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:18:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_VERTEX_H

// get_vertex.c

void	set_vertex(t_vertex *vertex,
			const float x, const float y, const float z);
void	cpy_vertex(t_vertex *vdest, const t_vertex *vsrc);
void	get_vertex(t_map *map, const int x, const int y, const char *format);

// color_vertex.c

void	get_color(t_vertex *vertex, const char *format,
			const int minz, const int maxz);
void	color_vertex(t_vertex *vertex, const int minz, const int maxz);

// color_utils.c

uint	sum_color(t_color color);
void	get_color_comp(t_color *color);
uint	get_red(float rad);
uint	get_green(float rad);
uint	get_blue(float rad);

#endif
