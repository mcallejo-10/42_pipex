# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 18:41:31 by mcallejo          #+#    #+#              #
#    Updated: 2024/02/09 16:48:43 by mcallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GREEN=\033[1;32m
RED=\033[1;31m
BLUE=\033[1;34m
YELLOW=\x1b[33;01m
END=\033[0m

#path dir
SRC_DIR = ./src
OBJ_DIR = ./obj
GNL_DIR = ./gnl
PRINTF_DIR = ./printf


LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_bzero.c ft_memcpy.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memset.c ft_memchr.c \
	ft_memcmp.c ft_memmove.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

GNL_SRC = get_next_line.c get_next_line_utils.c

PRINTF_SRC = ft_printf.c ft_print_str.c ft_print_char.c ft_print_int.c \
	ft_print_unsigned.c ft_print_hex.c ft_print_upphex.c ft_print_pointer.c

INCLUDE = libft.h 

#crea los archivos .o
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(LIBFT_SRC:.c=.o)) $(notdir $(GNL_SRC:.c=.o)) $(notdir $(PRINTF_SRC:.c=.o)))

DEPS = $(OBJECTS:.o=.d)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

#objetivo para hacer doc de la libreria
all: $(NAME)

# Incluir las reglas de dependencias generadas por el compilador
-include $(DEPS)

###################### LIBFT ##################################################
# Generar las dependencias
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	@$(CC) -MM -MF $@ -MT $(@:%.d=%.o) $(CFLAGS) $<
#compila los .c y genera las dependencias
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -I ./ -MMD -MP -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

#################### GNL ######################################################
# Generar las dependencias
$(OBJ_DIR)/%.d: $(GNL_DIR)/%.c 
	@$(CC) -MM -MF $@ -MT $(@:.d=.o) $(CFLAGS) $<
#compila los .c y genera las dependencias
$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -I ./ -MMD -MP -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

###################### PRINTF ################################################# 
# Generar las dependencias
$(OBJ_DIR)/%.d: $(PRINTF_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	@$(CC) -MM -MF $@ -MT $(@:.d=.o) $(CFLAGS) $<
#compila los .c y genera las dependencias
$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -I ./ -MMD -MP -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

#crea el archivo de la librería
$(NAME): $(OBJECTS)
	@$(AR) -rsc $@ $^
	@echo "$(GREEN)LIBFT DONE$(END)"


clean:
	@rm -rf $(OBJ_DIR) $(DEPS)
	@echo "$(RED)LIBFT OBJS DELETED $(END)"
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)LIBFT EXEC DELETED $(END)"

re: fclean all
-include $(DEPS)

.PHONY: all clean fclean re
