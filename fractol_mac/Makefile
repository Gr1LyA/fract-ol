# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharland <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 20:13:12 by tharland          #+#    #+#              #
#    Updated: 2021/11/22 20:13:13 by tharland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = MONDELBROT.c JULIA.c main.c algebra.c tools.c sub_func.c STATIC_JULIA.c init_fractal.c JULIAX3.c
OBJS = ${SRCS:.c=.o}
CC = gcc -Wall -Wextra -Werror -fsanitize=address


%.o: %.c
		$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS) fractol.h Makefile
		make -C ./mlx
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:	$(NAME)

clean:
		rm -rf $(OBJS) fractol

fclean:	clean
		rm -rf $(NAME)
		make clean -C ./mlx

re:	fclean re all
