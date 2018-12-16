# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 12:34:08 by fbueno-m          #+#    #+#              #
#    Updated: 2018/06/04 12:34:09 by fbueno-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	main.c \
		draw_map.c \
		draw_line.c \
		utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft re
	@make -C libft clean
	@make -C minilibx_macos re
	@cc -Wall -Wextra -Werror -c $(SRC)
	@cc -Wall -Wextra -Werror -I ./minilibx_macos -L ./minilibx_macos -lmlx -L \
	./libft -lft -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@make clean

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
