/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/03 21:59:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <X.h> //precise path in Makefile
# include <keysymdef.h> //precise path in Makefile

# define ESCAPE_KEY 65307

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

// window

t_win	*init_window(const int height, const int width, char *title);
void	destroy_window(t_win *window);
int		close_window1(int key, t_win *ptr);
int		close_window2(t_win *ptr);

// events

void	loop(t_win *window);

// print

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_shap(t_data *img, int height, int width);

#endif
