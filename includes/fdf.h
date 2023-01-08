/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/08 14:57:06 by rbroque          ###   ########.fr       */
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

//////////////////
/// DIMENSIONS ///
//////////////////

# ifndef HEIGHT
#  define HEIGHT 1600
# endif

# ifndef WIDTH
#  define WIDTH 1200
# endif

# define MIN_WIDTH 2
# define MIN_HEIGHT 2

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
	t_data	*data;
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

char	***parse(const char *path_file);

// read.c

bool	is_valid_file(char **content);
char	**get_file_content(const char *path_file, const size_t size);
size_t	get_file_size(const char *path_file);
void	free_parsing(char ****parsing);

/// WINDOW ///

// free_window.c

void	free_window(t_win *window);

// init_win.c

t_win	*init_window(void);

// DATA //

// free_data.c

void	free_data(t_data *data, void *mlx_ptr);

// init_data.c

t_data	*init_data(void *mlx_ptr);

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
