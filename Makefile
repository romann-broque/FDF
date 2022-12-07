# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2022/12/06 23:51:04 by rbroque          ###   ########.fr        #
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
PATH_SRCS += srcs/loop/

# srcs/

SRCS += main.c

# srcs/struct

SRCS += window.c
SRCS += data.c
SRCS += pos.c

# srcs/loop

SRCS += events.c
SRCS += loop.c

# srcs/print

SRCS += print.c

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

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo -ne "\r [`expr $C '*' 100 / $T`%]"
endif

###############
#### RULES ####
###############

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS)
	@echo -ne "\r$@ COMPILED !"

$(LIB):
	@$(MAKE) -C $(LIB_FOLDER)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(MAKEFILE)
	@$(ECHO) COMPILING $>
	sleep 0.2
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -O3

run:
	$(MAKE)
	./$(NAME)

clean:
	@echo -ne "\rcleaning .o"
	@$(RM) -R $(PATH_OBJS)
	@$(MAKE) -sC $(LIB_FOLDER) clean

fclean: clean
	@echo -ne "\rcleaning $(NAME)"
	@$(RM) $(NAME)
	@$(MAKE) -sC $(LIB_FOLDER) fclean

re: fclean
	@$(MAKE) -s

.PHONY: all clean fclean re run

#endif
