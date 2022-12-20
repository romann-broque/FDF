# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 10:15:13 by rbroque           #+#    #+#              #
#    Updated: 2022/12/20 23:49:28 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
#### ENV ####
#############

SHELL = /usr/bin/bash

##############
#### NAME ####
##############

NAME = libft.a

##############
#### SRCS ####
##############

PATH_SRCS += srcs/
PATH_SRCS += srcs/conv/
PATH_SRCS += srcs/ctype/
PATH_SRCS += srcs/gnl/
PATH_SRCS += srcs/list/
PATH_SRCS += srcs/memory/
PATH_SRCS += srcs/output/
PATH_SRCS += srcs/strings/

# ctype

SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_islower.c
SRCS += ft_isprint.c
SRCS += ft_isupper.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# conv

SRCS += ft_atoi.c
SRCS += ft_itoa.c

# gnl

SRCS += get_next_line.c

# list

SRCS += ft_lstadd_back.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstclear.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstlast.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstsize.c

# memory

SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c

# output

SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c

# strings

SRCS += index_of.c
SRCS += ft_split.c
SRCS += ft_split_set.c
SRCS += ft_strchr.c
SRCS += ft_strcpy.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strncpy.c
SRCS += ft_strndup.c
SRCS += ft_strnjoin.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c

vpath %.c $(PATH_SRCS)

###############
#### OBJS #####
###############

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##################
#### INCLUDES ####
##################

INCLUDES += includes/

#####################
#### COMPILATION ####
#####################

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra

ifneq ($(noerr), true)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
endif

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
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

$(NAME): $(OBJS)
	ar rcs $@ $^
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(ECHOC) $(YELLOW) "Cleaning up .o files..." $(NC)
	$(RM) -R $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files cleaned !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) cleaned !"$(NC)"\n"

re: fclean
	echo -e $(YELLOW) "\nRebuilding...\n" $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re
.SILENT: