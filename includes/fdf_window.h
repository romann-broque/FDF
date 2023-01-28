/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:12:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_WINDOW_H

// free_window.c

void	free_window(t_win *window);

// init_win.c

void	init_window(t_win *window, char ***parsing);

// is_window_initialised.c

bool	is_window_initialised(const t_win *window);

#endif
