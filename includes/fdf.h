/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/07 18:06:14 by rbroque          ###   ########.fr       */
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
#  define HEIGHT 50
# endif

# ifndef WIDTH
#  define WIDTH 50
# endif

# define MIN_WIDTH 2
# define MIN_HEIGHT 2

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

int	fdf(const char *path_file);

/// PARSER ///

// read.c

bool	is_valid_file(char **content);
char	**get_file_content(const char *path_file, const size_t size);
size_t	get_file_size(const char *path_file);
void	free_parsing(char ***parsing);

// parser.c

char	***parse(const char *path_file);

// is_valid_parsing.c

bool	is_parsing_valid(char ***parsing);

/// WINDOW ///

// free_data.c

void	free_data(t_data *data, void *mlx_ptr);

// init_data.c

t_data	*init_data(void *mlx_ptr);

// free_window.c

void	free_window(t_win *window);

// init_win.c

t_win	*init_window(void);

// loop.c

void	loop(t_win *window);

// display_window.c

void	display_window(t_win *window);

#endif
