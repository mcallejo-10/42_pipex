# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcallejo <mcallejo@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 12:03:47 by mcallejo          #+#    #+#              #
#    Updated: 2024/02/24 20:14:43 by mcallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = pipex

SOURCES = main_pipex.c error.c

OBJECTS = $(SOURCES:%.c=%.o)

CFLAGS = #-Wall -Werror -Wextra -I./

CC = gcc

LIBFT = my_libft/lft.h
LIBFT_FLAGS = -L ./my_libft -lft

%.o: %.c Makefile
	$(CC) -c $< $(CFLAGS)  -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C ./my_libft --no-print-directory

$(NAME): Makefile $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)PIPEX DONE$(END)"

clean:
	@rm -rf $(OBJECTS) 
	@$(MAKE) -C ./my_libft clean --no-print-directory
	@echo "$(RED)OBJECTS DELETED$(END)"
	
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./my_libft fclean --no-print-directory
	@echo "$(RED)EXEC DELETED $(END)"
	
re: fclean all

.PHONY: all clean fclean re

