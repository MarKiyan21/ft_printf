#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 10:13:19 by mkyianyt          #+#    #+#              #
#    Updated: 2017/03/31 11:55:05 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_memset.c ft_memalloc.c ft_strlen.c ft_strdup.c ft_strncat.c\
	  ft_strcpy.c ft_strcat.c ft_atoi.c ft_strnew.c ft_putchar.c ft_putstr.c\
	  ft_strrev.c ft_uppercase.c bits_help.c fill_s.c ft_printf.c ft_strncpy.c\
	  functions.c identify_specificator.c init_flags_with_spec.c\
	  init_other_flags.c initialize.c my_itoa_base.c my_unsigned_itoa_base.c\
	  other_flags.c type_c.c type_d.c type_o.c type_p.c type_s.c type_u.c\
	  type_wchar.c type_x.c write_char.c ft_strstr.c

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)