/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:39:45 by rbroque          ###   ########.fr       */
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

# include "fdf_struct.h"
# include "fdf_defines.h"
# include "fdf_data.h"
# include "fdf_display.h"
# include "fdf_error.h"
# include "fdf_loop.h"
# include "fdf_map.h"
# include "fdf_parser.h"
# include "fdf_transform.h"
# include "fdf_vertex.h"
# include "fdf_window.h"

// fdf.c

int		fdf(const char *path_file);

#endif
