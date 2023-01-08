/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 16:13:53 by rbroque          ###   ########.fr       */
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

///////////////////
/// KEY_MAPPING ///
///////////////////

# define ESCAPE_KEY 65307
# define NO_KEY 0

//////////////////////////////
//// <----- STRUCT -----> ////
//////////////////////////////

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
}				t_win;

typedef struct s_event_mapping
{
	int	key;
	int	(*event)(t_win *);

}				t_event_mapping;

/////////////////////////////////
//// <----- FUNCTIONS -----> ////
/////////////////////////////////

// fdf.c

int		fdf(const char *path_file);

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

void	init_window(t_win *window);

// DATA //

// free_data.c

void	free_data(t_data *data, void *mlx_ptr);

// init_data.c

void	init_data(void *mlx_ptr, t_data *dest);

// LOOP //

// events.c

int		close_window(t_win *ptr);

// keyboard.c

int		key_press(int key, t_win *window);

// loop.c

void	loop(t_win *window);

// DISPLAY //

// display_window.c

void	display_window(t_win *window);

#endif
