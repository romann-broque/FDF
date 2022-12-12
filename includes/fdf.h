/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2022/12/12 18:22:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <X.h>
# include <keysymdef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESCAPE_KEY 65307

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef ZOOM
#  define ZOOM 20
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

typedef struct	s_pos
{
	int	x;
	int	y;
	int	z;
}				t_pos;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;
	int		zoom;
	t_pos	***orig_matrix;
	t_pos	***refr_matrix;
}				t_win;

/// loop ///

// events

int		close_window1(int key, t_win *ptr);
int		close_window2(t_win *ptr);
int		detect_mouse_pos(int x, int y, t_win *ptr);
int		zoom(int x, int y, int key, t_win *ptr);

// loop

void	loop(t_win *window);

/// math ///

int		get_sign(int nb);
void	ft_swap(int *nb1, int *nb2);
int		get_max(const int nb1, const int nb2);

/// map

t_pos	***get_pos_matrix(int fd, int zoom, size_t size);

/// print ///

// print

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_ref(t_data *img, int height, int width);

// print_map

void	print_map(t_pos ***pos_array, t_win *window);

// print_line

void	print_line(t_pos *pos1, t_pos *pos2, t_data *data, int color);

/// struct ///

// data

t_data	*init_data(void *mlx_ptr);

// pos

void	set_offset(t_pos **pos_array, int zoom);
t_pos	set_pos(t_pos *pos, int x, int y, int z);
t_pos	*init_pos(int x, int y, int z);

// window

t_win	*init_window(const int height, const int width, char *title, t_pos ***orig_matrix);
void	destroy_window(t_win *window);

// array

size_t	get_pos_array_size(t_pos **pos_array);
void	free_strs(char **array);
void	free_pos_array(t_pos **pos_array);

// matrix

size_t	get_matrix_size(const char *path);
size_t	get_pos_matrix_size(t_pos ***pos_array);
void	free_pos_matrix(t_pos ***pos_matrix);

/// utils ///

// string

size_t	strcountchr(const char *str, const char c);
size_t	get_array_size_char(char **array);

#endif
