/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/27 17:57:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define XK_LATIN1
# define XK_MISCELLANY

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <X.h>
# include <keysymdef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

///////////////////////////////
//// <----- DEFINES -----> ////
///////////////////////////////

# define EXPECT_COUNT_ARG	2
# define ON					1
# define OFF				0

//////////////
/// PARSER ///
//////////////

# define SEPARATOR		','
# define HEX_BASE		"0123456789abcdef"
# define COLOR_PREFIX	"0x"

/////////////
/// ERROR ///
/////////////

# define INVALID_PARSING_ERROR "Invalid map"

//////////////
/// WINDOW ///
//////////////

# define WINDOW_TITLE "FDF"

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

///////////
/// HUD ///
///////////

# define CTRL_TITLE		"CONTROLS"
# define CTRL_WIDTH		200
# define CTRL_HEIGHT	230
# define VIEW_WIDTH		200
# define VIEW_HEIGHT	20

/////////////////
/// TRANSFORM ///
/////////////////

# define MIN_HEIGHT				2
# define MIN_WIDTH				2
# define MAX_ZOOM				SIZE_MAX
# define MIN_ZOOM				1
# define ZOOM					3
# define ZOOM_SHIFT				1
# define X_ANGLE				0.0
# define Y_ANGLE				0.0
# define Z_ANGLE				0.0
# define ANGLE_SHIFT			0.1
# define ALTITUDE				-0.1
# define ALTITUDE_SHIFT			0.01
# define ALTITUDE_SHIFT_BOOST	1
# define X_OFFSET				0
# define Y_OFFSET				0
# define OFFSET_SHIFT			10

/////////////
/// COLOR ///
/////////////

# define RED_MASK			0xFF0000
# define GREEN_MASK			0x00FF00
# define BLUE_MASK			0x0000FF
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define YELLOW				0x00FF00
# define BLUE				0x0000FF
# define GREEN				0x00FF00
# define LIGHT_BLUE			0x00FFFF

///////////////////
/// KEY_MAPPING ///
///////////////////

# define K_ESC		0xff1b
# define K_XROT1	0x0077  /* U+0077 LATIN SMALL LETTER W */
# define K_XROT2	0x0073  /* U+0073 LATIN SMALL LETTER S */
# define K_YROT1	0x0061  /* U+0061 LATIN SMALL LETTER A */
# define K_YROT2	0x0064  /* U+0064 LATIN SMALL LETTER D */
# define K_ZROT1	0x0071  /* U+0071 LATIN SMALL LETTER Q */
# define K_ZROT2	0x0065  /* U+0065 LATIN SMALL LETTER E */
# define K_ZOOM		0x003d  /* U+003D EQUALS SIGN */
# define K_UNZOOM	0x002d  /* U+002D HYPHEN-MINUS */
# define K_ALT1		0x006f  /* U+006F LATIN SMALL LETTER O */
# define K_ALT2		0x0070  /* U+0070 LATIN SMALL LETTER P */
# define K_ALT3		0x0075  /* U+0075 LATIN SMALL LETTER U */
# define K_ALT4		0x0069  /* U+0069 LATIN SMALL LETTER I */
# define K_UP		0xff52  /* Move up, up arrow */
# define K_DOWN		0xff54  /* Move down, down arrow */
# define K_LEFT		0xff51  /* Move left, left arrow */
# define K_RIGHT	0xff53  /* Move right, right arrow */
# define K_CENTER	0x0063  /* U+0063 LATIN SMALL LETTER C */
# define K_RESET	0x0072  /* U+0072 LATIN SMALL LETTER R */
# define K_HUD		0x0068  /* U+0068 LATIN SMALL LETTER H */
# define K_FREE		0x0030  /* U+0030 DIGIT ZERO */
# define K_ISO		0x0031  /* U+0031 DIGIT ONE */
# define K_MILIT	0x0032  /* U+0032 DIGIT TWO */
# define NO_KEY		0

//////////////////////////////
//// <----- STRUCT -----> ////
//////////////////////////////

typedef enum e_angle
{
	E_XANGLE,
	E_YANGLE,
	E_ZANGLE,
}				t_angle;

typedef enum e_view
{
	E_ISOMETRIC,
	E_MILITARY,
	E_FREE,
}				t_view;

typedef struct s_color
{
	uint	red;
	uint	green;
	uint	blue;
	uint	sum;
}				t_color;

typedef struct s_imginfo
{
	int		width;
	int		height;
	int		x_offset;
	int		y_offset;
}				t_imginfo;

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	t_color	color;
}				t_vertex;

typedef struct s_line
{
	t_vertex	v1;
	t_vertex	v2;
	long		dx;
	int			sx;
	long		dy;
	int			sy;
	long		error;
	long		e2;
	size_t		nb_points;

}				t_line;

typedef struct s_map
{
	t_vertex	**vertex;
	t_vertex	**vcpy;
	t_vertex	center;
	size_t		x_size;
	size_t		y_size;
	int			minz;
	int			maxz;
	t_view		view;
	double		zoom;
	double		altitude;
	int			x_offset;
	int			y_offset;
	double		x_angle;
	double		cosx;
	double		sinx;
	double		y_angle;
	double		cosy;
	double		siny;
	double		z_angle;
	double		cosz;
	double		sinz;
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
	bool	hud_status;
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

/// ERROR ///

void	print_error(char *error_message);

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

// parser_utils.c

bool	is_color_prefix_valid(const char *format);
bool	is_format_valid(const char *str);

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

// EVENTS//

// e_close_window.c

int		close_window(t_win *ptr);

// e_zoom.c

int		increase_zoom(t_win *window);
int		decrease_zoom(t_win *window);

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

// keyboard.c

int		key_press(int key, t_win *window);

// loop.c

void	loop(t_win *window);

// MAP //

// init_map.c

void	cpy_vertex_map(t_vertex **vdest, t_vertex **vsrc,
			const size_t x_size, const size_t y_size);
void	init_map(t_map *map, char ***parsing);

// get_map_size.c

size_t	get_size_strs(char **parsed_line);
size_t	get_x_size(char ***parsing);
size_t	get_y_size(char ***parsing);

// map_utils.c

void	destroy_vertex_map(t_vertex ***v_map);
void	set_map_color(t_map *map, char ***parsing);
void	free_map(t_map *map);

// VERTEX //

// get_vertex.c

void	set_vertex(t_vertex *vertex,
			const float x, const float y, const float z);
void	get_vertex(t_map *map, const int x, const int y, const char *format);

// color_vertex.c

void	get_color(t_vertex *vertex, const char *format,
			const int minz, const int maxz);
void	color_vertex(t_vertex *vertex, const int minz, const int maxz);

// color_utils.c

uint	sum_color(t_color color);
void	get_color_comp(t_color *color);
uint	get_red(float rad);
uint	get_green(float rad);
uint	get_blue(float rad);

// DISPLAY //

// refresh.c

void	refresh(t_win *window);

// display_map.c

void	display_map(t_win *window);

// display_window.c

void	display_window(t_win *window);

// HUD //

// hud_utils.c

void	cpy_imginfo(t_imginfo *dest, const t_imginfo *src);
void	display_controls(t_win *window, char *text, const t_imginfo *img);
void	display_interface(t_win *window,
			char *text, const t_imginfo *img, const int color);

// hud_strings.c

void	print_string(const t_win *window,
			char *str, const t_imginfo *img, const int color);
void	print_center_text(t_win *window,
			char *text, const t_imginfo *img, const int color);

// print_hud.c

void	print_info(const t_win *window, const t_imginfo *img);
void	print_view(t_win *window, const t_imginfo *img, int color);

// display_hud.c

void	display_hud(t_win *window);

// LINE //

// init_line.c

void	init_line(t_line *line, const t_vertex *v1, const t_vertex *v2);

// line_utils.c

bool	is_line_printable(t_line *line);
bool	are_crd_same(const double c1, const double c2);
bool	are_pos_same(const t_vertex *v1, const t_vertex *v2);

// POINT //

// put_pixel.c

void	put_pixel(t_data *data, int x, int y, int color);

// put_utils.c

int		get_point_color(const t_vertex *v1, const t_vertex *v2,
			const float interpol_factor);
float	get_interpol_factor(const t_vertex *v1, const t_vertex *v2,
			const size_t pts_nb);

// put_point.c

void	put_point(t_data *data, const t_line *line);

// put_line.c

int		get_sign(const double nb);
void	put_line(t_data *data, const t_vertex *v1, const t_vertex *v2);

// TRANSFORM //

// altitude.c

void	altitude(const t_map *map);

// zoom.c

void	zoom(const t_map *map);

// center.c

void	center(t_map *map, const int x_offset, const int y_offset);

// offset.c

void	offset(t_map *map, const float x_offset, const float y_offset);

// rotate.c

void	rotate(t_map *map);

// transform_map.c

void	transform_map(t_map *map);

#endif
