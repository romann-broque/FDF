# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2023/03/01 18:32:21 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
#### ENV ####
#############

SHELL = /usr/bin/bash

##############
#### NAME ####
##############

NAME = fdf
DEFAULT_ARG = ./assets/test_maps/default/42.fdf

##############
#### SRCS ####
##############

PATH_SRCS += srcs/
PATH_SRCS += srcs/parser/
PATH_SRCS += srcs/error
PATH_SRCS += srcs/window/
PATH_SRCS += srcs/window/data/
PATH_SRCS += srcs/window/display/
PATH_SRCS += srcs/window/display/line/
PATH_SRCS += srcs/window/display/line/point
PATH_SRCS += srcs/window/display/hud/
PATH_SRCS += srcs/window/loop/
PATH_SRCS += srcs/window/loop/events/
PATH_SRCS += srcs/window/loop/events/angle/
PATH_SRCS += srcs/window/map/
PATH_SRCS += srcs/window/map/vertex/
PATH_SRCS += srcs/window/map/vertex/color/
PATH_SRCS += srcs/window/transform/

# srcs/

SRCS += main.c
SRCS += fdf.c

# srcs/error/

SRCS += print_error.c

# srcs/parser/

SRCS += is_valid_parsing.c
SRCS += parser.c
SRCS += read.c
SRCS += parser_utils.c

# srcs/window/

SRCS += init_window.c
SRCS += is_window_initialised.c
SRCS += free_window.c

# srcs/window/data/

SRCS += init_data.c
SRCS += free_data.c

# srcs/window/display/

SRCS += display_window.c
SRCS += display_map.c
SRCS += refresh.c

# srcs/window/display/line/

SRCS += init_line.c
SRCS += line_utils.c
SRCS += put_line.c

# srcs/window/display/line/point/

SRCS += point_utils.c
SRCS += put_pixel.c
SRCS += put_point.c

# srcs/window/display/hud/

SRCS += display_hud.c
SRCS += hud_utils.c
SRCS += print_hud.c
SRCS += hud_strings.c

# srcs/window/map/

SRCS += init_map.c
SRCS += map_utils.c
SRCS += get_map_size.c

# srcs/window/map/vertex/

SRCS += get_vertex.c

# srcs/window/map/vertex/color/

SRCS += color_vertex.c
SRCS += color_utils.c

# srcs/window/loop/

SRCS += keyboard.c
SRCS += loop.c

# srcs/window/loop/events/

SRCS += e_altitude.c
SRCS += e_center.c
SRCS += e_close_window.c
SRCS += e_offset.c
SRCS += e_reset.c
SRCS += e_zoom.c
SRCS += e_hud.c
SRCS += e_view.c

# srcs/window/loop/events/angle/

SRCS += e_angle.c
SRCS += e_xangle.c
SRCS += e_yangle.c
SRCS += e_zangle.c

# srcs/window/transform

SRCS += transform_map.c
SRCS += altitude.c
SRCS += offset.c
SRCS += rotate.c
SRCS += center.c
SRCS += zoom.c

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#############
#### LIB ####
#############

LIB_FOLDER = libft/
LIB = $(LIB_FOLDER)/libft.a
MLX_FOLDER = minilibx-linux/
MINILIBX += $(MLX_FOLDER)/libmlx_Linux.a
MINILIBX += $(MLX_FOLDER)/libmlx.a
MINILIBX_TAR += minilibx-linux.tgz
MINILIBX_LINK += https://cdn.intra.42.fr/document/document/17935/$(MINILIBX_TAR)

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
INCLUDES_LIB += -I $(MLX_FOLDER)
INCLUDES_LIB += -I /usr/include/X11/
INCLUDES += includes/

LINKS += -Lminilibx-linux -lmlx_Linux
LINKS += -L/usr/lib -lXext -lX11 -lm -lz

#################
#### HEADERS ####
#################

HEADERS += fdf.h
HEADERS += fdf_data.h
HEADERS += fdf_defines.h
HEADERS += fdf_display.h
HEADERS += fdf_error.h
HEADERS += fdf_loop.h
HEADERS += fdf_map.h
HEADERS += fdf_parser.h
HEADERS += fdf_struct.h
HEADERS += fdf_transform.h
HEADERS += fdf_vertex.h
HEADERS += fdf_window.h

vpath %.h $(INCLUDES)

##################
#### MAKEFILE ####
##################

MAKEFILE = Makefile

#####################
#### COMPILATION ####
#####################

CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra

ifneq ($(noerror), 1)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
endif

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############
#### RULES ####
###############

all: $(MINILIBX) $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(MINILIBX_TAR):
	echo -e $(BLUE) "\n====> Downloading MLX <===="$(NC)"\n"
	wget $(MINILIBX_LINK) &> /dev/null
	tar -zxvf $(MINILIBX_TAR) &> /dev/null
	$(ECHOC) $(GREEN) "--> MLX DOWNLOADED !"$(NC)"\n"

$(MINILIBX): $(MINILIBX_TAR)
	echo -e $(BLUE) "\n====> Building MLX <===="$(NC)"\n"
	$(MAKE) -sC $(MLX_FOLDER) &> /dev/null
	$(ECHOC) $(GREEN) "--> MLX COMPILED !"$(NC)"\n"

$(LIB):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIB_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -O3

run:
	$(MAKE) -s
	./$(NAME) $(DEFAULT_ARG)

norm:
	norminette $(PATH_SRCS) $(INCLUDES) $(LIB_FOLDER)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(MLX_FOLDER) clean > /dev/null
	$(MAKE) -sC $(LIB_FOLDER) clean > /dev/null
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIB_FOLDER) fclean > /dev/null
	$(RM) $(NAME)
	$(RM) $(MINILIBX_TAR)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(MINILIBX_TAR) deleted !"$(NC)"\n"

re: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	echo -e $(BLUE) "\n====> Building MLX <===="$(NC)"\n"
	$(MAKE) -sC $(MLX_FOLDER) re &> /dev/null
	$(ECHOC) $(GREEN) "--> MLX COMPILED !"$(NC)"\n"
	$(MAKE) -s

.PHONY: all clean fclean re run
.SILENT: $(NAME) $(LIB) $(MINILIBX) $(MINILIBX_TAR) $(OBJS) run clean fclean re test
