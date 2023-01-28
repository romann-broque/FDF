/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:16:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H

// init_map.c

void	cpy_vertex_map(t_vertex **vdest, t_vertex **vsrc,
			const size_t x_size, const size_t y_size);
void	init_map(t_map *map, char ***parsing);

// get_map_size.c

size_t	get_size_strs(char **parsed_line);
size_t	get_x_size(char ***parsing);
size_t	get_y_size(char ***parsing);

// map_utils.c

void	destroy_vertex_map(t_vertex ***v_map);
void	set_map_color(t_map *map, char ***parsing);
void	free_map(t_map *map);

#endif
