# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2023/01/16 16:57:40 by rbroque          ###   ########.fr        #
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
PATH_SRCS += srcs/window/data
PATH_SRCS += srcs/window/display
PATH_SRCS += srcs/window/loop
PATH_SRCS += srcs/window/map
PATH_SRCS += srcs/window/map/vertex
PATH_SRCS += srcs/window/transform

# srcs/

SRCS += main.c
SRCS += fdf.c

# srcs/error/

SRCS += print_error.c

# srcs/parser/

SRCS += is_valid_parsing.c
SRCS += parser.c
SRCS += read.c

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
SRCS += put_line.c
SRCS += put_pixel.c

# srcs/window/map/

SRCS += init_map.c
SRCS += free_map.c
SRCS += get_map_size.c

# srcs/window/map/vertex

SRCS += get_vertex.c

# srcs/window/loop

SRCS += events.c
SRCS += keyboard.c
SRCS += loop.c

# srcs/window/transform

SRCS += transform_map.c
SRCS += altitude.c
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

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
INCLUDES_LIB += -I /usr/include/X11/
INCLUDES_LIB += -I minilibx-linux/
INCLUDES += includes/

LINKS += -Lminilibx-linux -lmlx_Linux
LINKS += -L/usr/lib -lXext -lX11 -lm -lz
HEADER += $(INCLUDES)/fdf.h

##################
#### MAKEFILE ####
##################

MAKEFILE = Makefile

###############
#### TESTS ####
###############

TEST_FOLDER = tests/
RUN_TESTS = $(TEST_FOLDER)run_tests

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
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############
#### RULES ####
###############

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(LIB):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIB_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -O3

run:
	$(MAKE) -s
	./$(NAME) $(DEFAULT_ARG)

norm:
	norminette $(PATH_SRCS) $(INCLUDES) $(PATH_LIB)

test:
	$(MAKE) -s
	$(MAKE) -sC $(TEST_FOLDER)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean > /dev/null
	$(MAKE) -sC $(TEST_FOLDER) clean > /dev/null
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIB_FOLDER) fclean > /dev/null
	$(MAKE) -sC $(TEST_FOLDER) fclean > /dev/null
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(RUN_TESTS) deleted !"$(NC)"\n"

re: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re run
.SILENT: $(NAME) $(LIB) $(OBJS) run clean fclean re test

#endif
