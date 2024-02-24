# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcallejo <mcallejo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:21:28 by mcallejo          #+#    #+#              #
#    Updated: 2023/10/24 16:46:50 by mcallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_print_str.c ft_print_char.c ft_print_int.c \
	ft_print_unsigned.c ft_print_hex.c ft_print_upphex.c ft_print_pointer.c

INCLUDE = ft_printf.h

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

CC = gcc

%.o: %.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJECTS)
	ar rcs $@ $? 

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
