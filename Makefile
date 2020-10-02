# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <rlein@student.hive.fi>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 10:59:40 by rklein            #+#    #+#              #
#    Updated: 2020/07/13 11:04:01 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCS = builtin.c \
	  cd.c \
	  cd_env.c \
	  echo.c \
	  env.c \
	  execute.c \
	  main.c \
	  minishell.c \
	  misc.c \
	  params.c \
	  semicolon.c \
	  setenv.c \
	  shell_env.c \
	  unsetenv.c

OBJ = $(SRCS:.c=.o) 

INC = ./includes

LIB = libft/libft.a

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(FLAGS) -c $(SRCS)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB) -I $(INC)

clean :
	rm -rf $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re : fclean all
