# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2022/12/06 21:25:24 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### NAME

NAME = fdf

### SRCS

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

### OBJS

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### LIB

LIB_FOLDER = libft/
LIB = $(LIB_FOLDER)/libft.a

### INCLUDES

INCLUDES_LIB = -I $(LIB_FOLDER)/includes/ -I /usr/include/X11/
INCLUDES += includes/
HEADER += $(INCLUDES)/fdf.h

### MAKEFILE

MAKEFILE = Makefile

### COMPILATION

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

### RULES

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

$(LIB):
	$(MAKE) -C $(LIB_FOLDER)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(MAKEFILE)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -Iminilibx-linux -O3

run:
	$(MAKE)
	./$(NAME)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIB_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all clean fclean re run
