# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlarson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 16:48:42 by hlarson           #+#    #+#              #
#    Updated: 2019/05/16 20:12:09 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRCS = ft_strjoin.c ft_strrjoin.c ft_strlen.c ft_strnew_zero.c ft_strnew_one.c ft_strnew.c ft_long_sum.c ft_long_composition.c ft_strdel.c ft_printf.h ft_one.c ft_zero.c ft_bzero.c take.c ft_long_pow.c ft_float.c ft_long_sum_dot.c create_until_percent.c ft_long_composition_dot.c ft_strdup.c ft_long_pow_minus.c ft_long_division.c get_after_dot_float.c get_before_dot_float.c ft_work_flag.c ft_octal.c ft_unsigned_int.c ft_hex.c ft_int.c count_numbers.c create_after_percent.c ft_long_double.c ft_work_flag_help.c ft_create_char.c ft_create_str.c ft_percent.c ft_pointer.c ft_get_all.c ft_atoi.c ft_memmove.c

OUT = ft_strjoin.o ft_strrjoin.o ft_strlen.o ft_strnew_zero.o ft_strnew_one.o ft_strnew.o ft_long_sum.o ft_long_composition.o ft_strdel.o ft_one.o ft_zero.o ft_bzero.o take.o ft_long_pow.o ft_float.o ft_long_sum_dot.o create_until_percent.o ft_long_composition_dot.o ft_strdup.o ft_long_pow_minus.o ft_long_division.o get_after_dot_float.o get_before_dot_float.o ft_work_flag.o ft_octal.o ft_unsigned_int.o ft_hex.o ft_int.o count_numbers.o create_after_percent.o ft_long_double.o ft_work_flag_help.o ft_create_char.o ft_create_str.o ft_percent.o ft_pointer.o ft_get_all.o ft_atoi.o ft_memmove.o

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c  $(SRCS) -I $(INCLUDES) 
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)
clean:
	rm -rf $(OUT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
