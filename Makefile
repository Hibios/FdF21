# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 11:05:38 by sstench           #+#    #+#              #
#    Updated: 2020/08/13 20:36:52 by sstench          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/libft.a minilibx_macos/libmlx.a

SRC_DIR = ./sources/
SRC_LST = main.c\
	window_size.c\
	set_param.c\
	read_map.c\
	draw_map.c\
	deal_key.c\
	ft_error.c\
	iso.c\
	
SRC = $(addprefix $(SRC_DIR), $(SRC_LST))

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
