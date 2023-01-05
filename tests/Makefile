# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:11:15 by rbroque           #+#    #+#              #
#    Updated: 2023/01/05 16:39:59 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
#### ENV ####
#############

SHELL = /usr/bin/bash

##############
#### NAME ####
##############

NAME = run_tests

##############
#### SRCS ####
##############

PATH_SRCS += srcs/

# srcs/

SRCS += main.c
SRCS += parser.test.c

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

FDF_CMPL = ../objs/*.o
FDF_OBJS = $(patsubst %/main.o, %, $(FDF_CMPL))

#############
#### LIB ####
#############

LIB_FOLDER = ../libft/
LIB = $(LIB_FOLDER)/libft.a

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
INCLUDES_LIB += -I /usr/include/X11/
INCLUDES_LIB += -I ../minilibx-linux/
INCLUDES += ../includes/
TEST_INCLUDES += includes/

LINKS += -L../minilibx-linux -lmlx_Linux
LINKS += -L/usr/lib -lXext -lX11 -lm -lz
HEADER += $(INCLUDES)/fdf.h
TEST_HEADER += $(TEST_INCLUDES)/run_tests.h

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

all:
	@echo BEFORE : $(FDF_CMPL)
	@echo THEN :   $(FDF_OBJS)
#$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(TEST_INCLUDES) $(INCLUDES_LIB) $(LIB) -O3

run:
	$(MAKE) -s
	./$(NAME) $(DEFAULT_ARG)

clean:
	$(RM) -R $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !\n"

re: fclean
	$(ECHOC) $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re run
.SILENT: $(NAME) $(OBJS) run clean fclean re