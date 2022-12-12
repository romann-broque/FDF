# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2022/12/12 18:21:02 by rbroque          ###   ########.fr        #
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

##############
#### SRCS ####
##############

PATH_SRCS += srcs/
PATH_SRCS += srcs/struct/
PATH_SRCS += srcs/print/
PATH_SRCS += srcs/math/
PATH_SRCS += srcs/loop/
PATH_SRCS += srcs/utils/

# srcs/

SRCS += main.c

# srcs/struct

SRCS += window.c
SRCS += map.c
SRCS += data.c
SRCS += pos.c
SRCS += array.c
SRCS += matrix.c

# srcs/loop

SRCS += events.c
SRCS += loop.c

# srcs/math

SRCS += utils.c

# srcs/print

SRCS += print.c
SRCS += print_line.c
SRCS += print_map.c

# srcs/utils

SRCS += string.c

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

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB)
	@$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(LIB):
	@echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	@$(MAKE) -sC $(LIB_FOLDER)
	@echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(MAKEFILE)
	@$(ECHO) $(ORANGE) "Compiling $<"
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -O3

run:
	@$(MAKE) -s
	./$(NAME)

norm:
	norminette $(PATH_SRCS) $(INCLUDES) $(PATH_LIB)
 
clean:
	@$(RM) -R $(PATH_OBJS)
	@$(MAKE) -sC $(LIB_FOLDER) clean > /dev/null
	@$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	@$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	@$(MAKE) -sC $(LIB_FOLDER) fclean > /dev/null
	@$(RM) $(NAME)
	@$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re: fclean
	@echo -e $(YELLOW) "\nRebuilding..." $(NC)
	@$(MAKE) -s

.PHONY: all clean fclean re run

#endif
