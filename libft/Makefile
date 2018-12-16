# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 16:24:59 by fbueno-m          #+#    #+#              #
#    Updated: 2018/04/18 16:25:01 by fbueno-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_lstdelone.c ft_putchar.c ft_strdup.c ft_strnstr.c \
ft_bzero.c ft_lstiter.c ft_putchar_fd.c ft_strequ.c ft_strrchr.c \
ft_count_words.c ft_lstmap.c ft_putendl.c ft_striter.c ft_strsplit.c \
ft_is_prime.c ft_lstnew.c ft_putendl_fd.c ft_striteri.c ft_strstr.c \
ft_is_whitespace.c ft_memalloc.c ft_putnbr.c ft_strjoin.c ft_strsub.c \
ft_isalnum.c ft_memccpy.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
ft_isalpha.c ft_memchr.c ft_putstr.c ft_strlen.c ft_swap.c ft_isascii.c \
ft_memcmp.c ft_putstr_fd.c ft_strmap.c ft_tolower.c ft_isdigit.c ft_memcpy.c \
ft_strcat.c ft_strmapi.c ft_toupper.c ft_isprint.c ft_memdel.c ft_strchr.c \
ft_strncat.c get_next_line.c ft_iterative_power.c ft_memmove.c ft_strclr.c \
ft_strncmp.c ft_itoa.c ft_memset.c ft_strcmp.c ft_strncpy.c ft_lstadd.c \
ft_mtxnew.c ft_strcpy.c ft_strnequ.c ft_lstdel.c ft_nbr_len.c ft_strdel.c \
ft_strnew.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I ./includes -O2
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
