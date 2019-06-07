# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 16:17:42 by dderevyn          #+#    #+#              #
#    Updated: 2019/01/18 20:05:00 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME):
	cd libft && make
	clang -Wall -Wextra -Werror ffillit/*.c -Llibft/ -lft -o fillit

norm:
	Norminette libft/*.c && Norminette libft/*.h && Norminette ffillit/*.c && Norminette ffillit/*.h

clean:
	/bin/rm -rf ffillit/*.o
	/bin/rm -rf *.o
	cd libft && make clean

fclean: clean
	/bin/rm -rf fillit && /bin/rm -rf libft/libft.a

re: fclean all

.PHONY: re all clean fclean norm $(NAMEA)
