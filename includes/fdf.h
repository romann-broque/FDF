/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/10 14:06:22 by rbroque          ###   ########.fr       */
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

///////////////////////////////
//// <----- DEFINES -----> ////
///////////////////////////////

# define EXPECT_COUNT_ARG 2

/////////////
/// ERROR ///
/////////////

# define INVALID_PARSING_ERROR "Invalid map"

//////////////
/// WINDOW ///
//////////////

# define WINDOW_TITLE "FDF"

//////////////////
/// DIMENSIONS ///
//////////////////

# ifndef WIDTH
#  define WIDTH 1600
# endif

# ifndef HEIGHT
#  define HEIGHT 1200
# endif

# define MIN_HEIGHT 2
# define MIN_WIDTH 2
# define ZOOM 50

/////////////
/// COLOR ///
/////////////

# define WHITE			0x00FFFFFF

/////////////
/// ERROR ///
/////////////

///////////////////
/// KEY_MAPPING ///
///////////////////

# define ESCAPE_KEY 65307
# define NO_KEY 0

//////////////////////////////
//// <----- STRUCT -----> ////
//////////////////////////////

typedef struct s_vertex
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_vertex;

typedef struct s_map
{
	t_vertex	**vertex;
	size_t		x_size;
	size_t		y_size;
}				t_map;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;
	t_map	map;
}				t_win;

typedef struct s_event_mapping
{
	int	key;
	int	(*event)(const t_win *);

}				t_event_mapping;

/////////////////////////////////
//// <----- FUNCTIONS -----> ////
/////////////////////////////////

// fdf.c

int		fdf(const char *path_file);

/// ERROR ///

void	print_error(const char *error_message);

/// PARSER ///

// is_valid_parsing.c

bool	is_parsing_valid(char ***parsing);

// parser.c

void	parse(char ****dest, const char *path_file);

// read.c

bool	is_valid_file(char **content);
char	**get_file_content(const char *path_file, const size_t size);
size_t	get_file_size(const char *path_file);
void	free_parsing(char ****parsing);

/// WINDOW ///

// free_window.c

void	free_window(t_win *window);

// init_win.c

void	init_window(t_win *window, char ***parsing);

// is_window_initialised.c

bool	is_window_initialised(const t_win *window);

// DATA //

// free_data.c

void	free_data(const t_data *data, void *mlx_ptr);

// init_data.c

void	init_data(void *mlx_ptr, t_data *dest);

// LOOP //

// events.c

int		close_window(const t_win *ptr);

// keyboard.c

int		key_press(int key, t_win *window);

// loop.c

void	loop(t_win *window);

// MAP //

// init_map.c

void	init_map(t_map *map, char ***parsing);

// get_map_size.c

size_t	get_size_strs(char **parsed_line);
size_t	get_x_size(char ***parsing);
size_t	get_y_size(char ***parsing);

// free_map.c

void	free_map(t_map *map);

// print_map.c

void	print_map(t_data *data, const t_map *map);

// VERTEX //

// get_vertex.c

void	get_vertex(t_vertex *vertex, const size_t x, const size_t y, const char *format);

// DISPLAY //

// display_window.c

void	display_window(t_win *window);

// put_pixel.c

void	put_pixel(t_data *data, int x, int y, int color);

// TRANSFORM //

// transform_map.c

void	transform_map(const t_map *map);

#endif
