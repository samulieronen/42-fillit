# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 15:51:07 by seronen           #+#    #+#              #
#    Updated: 2019/12/19 16:28:40 by seronen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/fillit.c srcs/check.c srcs/make_map.c srcs/mod_tetri.c \
	srcs/solve_tetri.c srcs/utils.c srcs/utils2.c

FLAGS = -Wall -Wextra -Werror

LIBFT = -I libft/includes -L libft/ -lft

all: $(NAME)

$(NAME):
	make -C libft/ re && make -C libft/ clean
	gcc $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT)

clean:
		/bin/rm -f

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all