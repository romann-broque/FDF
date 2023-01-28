/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:25:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/28 02:40:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINES_H

# define EXPECT_COUNT_ARG	2
# define ON					1
# define OFF				0

/////////////
/// ERROR ///
/////////////

# define INVALID_PARSING_ERROR "Invalid map"

//////////////
/// PARSER ///
//////////////

# define SEPARATOR		','
# define HEX_BASE		"0123456789abcdef"
# define COLOR_PREFIX	"0x"

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
# define VIEW_COUNT		4

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
# define K_ELEV		0x0033  /* U+0033 DIGIT THREE */
# define NO_KEY		0

#endif
