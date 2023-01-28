/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:24:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:30:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H

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
	E_ELEVATION,
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

#endif
