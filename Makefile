# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <rlein@student.hive.fi>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 10:59:40 by rklein            #+#    #+#              #
#    Updated: 2020/06/30 13:47:50 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRC = main.c minishell.c shell_env.c params.c misc.c builtin.c execute.c cd.c \
	  cd_env.c env.c setenv.c unsetenv.c echo.c

OBJ = main.o minishell.o shell_env.o params.o misc.o builtin.o execute.o cd.o \
	  cd_env.o env.o setenv.o unsetenv.o echo.o

INC = ./

LIB = libft/libft.a

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB) -I $(INC)

clean :
	rm -rf $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re : fclean all
