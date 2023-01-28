/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:14:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LOOP_H

// EVENTS//

// e_close_window.c

int		close_window(t_win *ptr);

// e_zoom.c

int		increase_zoom(t_win *window);
int		decrease_zoom(t_win *window);

// e_altitude.c

int		increase_altitude(t_win *window);
int		decrease_altitude(t_win *window);
int		increase_altitude_boost(t_win *window);
int		decrease_altitude_boost(t_win *window);

// e_offset.c

int		up(t_win *window);
int		down(t_win *window);
int		left(t_win *window);
int		right(t_win *window);

// e_center.c

int		center_offset(t_win *window);

// e_reset.c

int		reset(t_win *window);

// e_hud.c

int		toggle_hud(t_win *window);

// e_view.c

int		free_view(t_win *window);
int		iso_view(t_win *window);
int		milit_view(t_win *window);
int		elev_view(t_win *window);

// keyboard.c

int		key_press(int key, t_win *window);

// loop.c

void	loop(t_win *window);

// ANGLE //

// e_angle.c

void	change_angle(t_win *window, t_angle angle, double rotation);

// e_xangle.c

int		increase_x_angle(t_win *ptr);
int		decrease_x_angle(t_win *ptr);

// e_yangle.c

int		increase_y_angle(t_win *ptr);
int		decrease_y_angle(t_win *ptr);

// e_zangle.c

int		increase_z_angle(t_win *ptr);
int		decrease_z_angle(t_win *ptr);

#endif
