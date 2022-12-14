/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/03 18:14:27 by rbroque          ###   ########.fr       */
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

//////////////////
/// RESOLUTION ///
//////////////////

# ifndef HEIGHT
#  define HEIGHT 900
# endif

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef MAX_ZOOM_OFFSET
#  define MAX_ZOOM_OFFSET 600
# endif

# ifndef MIN_ZOOM_OFFSET
#  define MIN_ZOOM_OFFSET 3
# endif

# ifndef ZOOM
#  define ZOOM MIN_ZOOM_OFFSET + 10
# endif

# ifndef ALTITUDE
#  define ALTITUDE 1
# endif

# ifndef MIN_ALTITUDE
#  define MIN_ALTITUDE 2
# endif

# ifndef MAX_ALTITUDE
#  define MAX_ALTITUDE 20
# endif

///////////////////
/// KEY_MAPPING ///
///////////////////

# define ESCAPE_KEY 65307
# define F_KEY 102
# define R_KEY 114
# define C_KEY 99
# define V_KEY 118
# define Z_KEY 122
# define X_KEY 120
# define SCROLL1_KEY 4
# define SCROLL2_KEY 5

//////////////
/// COLORS ///
//////////////

# define CONTRAST		50
# define CONTRAST_SHIFT	0x000000F0
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF
# define YELLOW			0x00FFFF00
# define WHITE			0x00FFFFFF
# define DEFAULT_COLOR	0x00FFFFFF

////////////
/// FILE ///
////////////

# define MAP_PATH "assets/test_maps/42.fdf"
# define MAP_NAME "FDF"

typedef struct	s_data {
	char	*addr;
	void	*img;
	int		contrast;
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

typedef struct	s_transform
{
	size_t	zoom;
	size_t	altitude;
	int	x_offset;
	int	y_offset;
	int	x_rot;
	int	y_rot;
	t_pos	*dimensions;
	t_pos	*center;
}				t_transform;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*data;
	t_transform	*transform;
	t_pos		***orig_matrix;
	t_pos		***refr_matrix;
}				t_win;



// typedef int t_key;
// typedef const int t_action_id;
// typedef struct s_action_key
// {
// 	 t_action_id action_id;
// 	 t_key key;
// }	 t_action_key;
// #define CLOSE 0


/// loop ///

// events

int		close_window1(int key, t_win *ptr);
int		close_window2(t_win *ptr);
int		detect_mouse_pos(int x, int y, t_win *ptr);
int		contrast(int key, t_win *window);

// keyboard

int		key_press(int key, t_win *window);

// mouse

int		mouse_press(int key, int x, int y, t_win *window);

// loop

void	loop(t_win *window);

/// math ///

int		get_sign(int nb);
void	ft_swap(int *nb1, int *nb2);
int		get_max(const int nb1, const int nb2);
int		get_min(const int nb1, const int nb2);

/// print ///

// print

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_ref(t_data *img, int height, int width);
void	put_pixel(t_data *data, int x, int y, int color);

// print_map

void	print_map(t_pos ***pos_array, t_win *window, unsigned int map);

// print_line

void	print_line(t_pos *pos1, t_pos *pos2, t_data *data, int color);

/// struct ///

// data

t_data	*init_data(void *mlx_ptr, int contrast);

// pos

t_pos	set_pos(t_pos *pos, int x, int y, int z);
void	cpy_pos(t_pos *dest, t_pos *src);
t_pos	*init_pos(int x, int y, int z);

// window

t_win	*init_window(const int height, const int width, char *title, t_pos ***orig_matrix, const size_t size);
void	destroy_window(t_win *window);
void	refresh(t_win *window);

// transform

t_transform	*init_transform(t_pos ***pos_matrix);
void		free_transform(t_transform *transform);
void		apply_persp(t_pos *curr_pos, t_pos *last_pos, t_transform *transform);
void		apply_transform(t_pos *pos, size_t x, t_transform *transform);

/// map ///

// array

size_t	get_pos_array_size(t_pos **pos_array);
void	free_strs(char **array);
void	free_pos_array(t_pos **pos_array);
t_pos	**dup_array(t_pos **src, const size_t array_size);

// matrix

size_t	get_matrix_size(const char *path);
size_t	get_pos_matrix_size(t_pos ***pos_array);
void	free_pos_matrix(t_pos ***pos_matrix);
void	cpy_matrix(t_pos ***dest, t_pos ***src);
t_pos	***dup_matrix(t_pos ***src, const size_t matrix_size);

/// map

t_pos	***get_pos_matrix(int fd, size_t size);
void	set_offset(t_pos ***pos_matrix, t_transform *transform);

/// utils ///

// string

size_t	strcountchr(const char *str, const char c);
size_t	get_array_size_char(char **array);

/// transform ///

// rotate

int	get_rot(t_transform *transform);
int	rotate(int key, t_win *window);

// altitude

int	get_altitude(int alt1, int alt2, t_transform *transform);
int	altitude(int key, t_win *window);

// zoom

int		zoom(int x, int y, int key, t_win *ptr);

// center

t_pos	*get_center(t_transform *transform);

// dimensions

t_pos *get_dimensions(t_pos ***pos_matrix);

#endif
