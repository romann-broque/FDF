/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/06 21:27:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <X.h>
# include <keysymdef.h>

# define ESCAPE_KEY 65307

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# ifndef WIDTH
#  define WIDTH 600
# endif

// COLORS

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00
# define WHITE	0x00FFFFFF

typedef struct	s_data {
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;
}				t_win;

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

/// loop

// events

int		close_window1(int key, t_win *ptr);
int		close_window2(t_win *ptr);
int		detect_mouse_pos(int x, int y, t_win *ptr);

// loop

void	loop(t_win *window);

/// print

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_ref(t_data *img, int height, int width);
void	print_line(t_pos *pos1, t_pos *pos2, t_data *data, int color);

/// struct

// data

t_data	*init_data(void *mlx_ptr);

// pos

void	set_pos(t_pos *pos, int x, int y);
t_pos	*init_pos(int x, int y);

// window

t_win	*init_window(const int height, const int width, char *title);
void	destroy_window(t_win *window);

#endif
