# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 16:10:08 by rklein            #+#    #+#              #
#    Updated: 2020/06/29 14:56:16 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

SRC = ft_printf.c ft_misc.c ft_base_print.c ft_char_print.c ft_double_print.c \
	ft_e_print.c ft_g_print.c ft_id_memory.c ft_int_print.c \
	ft_uint_print.c ft_double_flags.c ft_int_flags.c ft_uint_flags.c \
	ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar.c ft_putendl.c ft_putstr.c \
	ft_strcat.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
	ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strsplit.c \
	ft_strsub.c ft_toupper.c

OBJ = ft_printf.o ft_misc.o ft_base_print.o ft_char_print.o ft_double_print.o \
	ft_e_print.o ft_g_print.o ft_id_memory.o ft_int_print.o \
	ft_uint_print.o ft_double_flags.o ft_int_flags.o ft_uint_flags.o \
	ft_atoi.o ft_isdigit.o ft_itoa.o ft_putchar.o  ft_putendl.o ft_putstr.o \
	ft_strcat.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strjoin.o \
	ft_strlen.o ft_strncmp.o ft_strncpy.o ft_strnew.o ft_strsplit.o \
	ft_strsub.o ft_toupper.o

INC = ./

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
