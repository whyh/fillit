# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 16:17:42 by dderevyn          #+#    #+#              #
#    Updated: 2018/11/16 16:55:53 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJ = *.o

.PHONY: re all clean fclean norm

$(NAME):
	clang -Wall -Wextra -Werror -c $(SRC) -I.libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

norm:
	Norminette .

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
