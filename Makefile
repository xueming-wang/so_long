# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 18:23:16 by xuwang            #+#    #+#              #
#    Updated: 2021/07/21 17:52:25 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc 
CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

# MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
MFLAGS	= -lmlx -framework OpenGL -framework AppKit


IFLAGS = -I. -I./libft

LFLAGS = -L./libft -lft

SRC	:= srcs/parser/check.c \
		srcs/parser/check_map.c \
		srcs/utils/exit.c \
		srcs/main.c \
		srcs/events/even_key.c \
		srcs/image/imag.c \
		
OBJ	:= $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	# $(MAKE) -C ./mlx
	# cp ./mlx/libmlx.dylib .
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@ 

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	# $(MAKE) -C ./mlx clean
	# rm -rf libmlx.dylib
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re