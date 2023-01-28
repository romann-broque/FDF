/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:19:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:53:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DISPLAY_H

// refresh.c

void	refresh(t_win *window);

// display_map.c

void	display_map(t_win *window);

// display_window.c

void	display_window(t_win *window);

// HUD //

// hud_utils.c

void	cpy_imginfo(t_imginfo *dest, const t_imginfo *src);
void	display_controls(t_win *window, char *text, const t_imginfo *img);
void	display_interface(t_win *window,
			char *text, const t_imginfo *img, const int color);

// hud_strings.c

void	print_string(const t_win *window,
			char *str, const t_imginfo *img, const int color);
void	print_center_text(t_win *window,
			char *text, const t_imginfo *img, const int color);

// print_hud.c

void	print_data_map(t_win *window);
void	print_info(const t_win *window, const t_imginfo *img);
void	print_view(t_win *window, const t_imginfo *img, int color);

// display_hud.c

void	display_hud(t_win *window);

// LINE //

// init_line.c

void	init_line(t_line *line, const t_vertex *v1, const t_vertex *v2);

// line_utils.c

bool	is_line_printable(t_line *line);
bool	are_crd_same(const double c1, const double c2);
bool	are_pos_same(const t_vertex *v1, const t_vertex *v2);

// POINT //

// put_pixel.c

void	put_pixel(t_data *data, int x, int y, int color);

// put_utils.c

int		get_point_color(const t_vertex *v1, const t_vertex *v2,
			const float interpol_factor);
float	get_interpol_factor(const t_vertex *v1, const t_vertex *v2,
			const size_t pts_nb);

// put_point.c

void	put_point(t_data *data, const t_line *line);

// put_line.c

int		get_sign(const double nb);
void	put_line(t_data *data, const t_vertex *v1, const t_vertex *v2);

#endif
