# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:09:18 by gissao-m          #+#    #+#              #
#    Updated: 2022/09/03 21:04:04 by hepiment         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang
INCLUDE = -I ./include/
CFLAGS = -g $(INCLUDE)
MLXFLAGS = -lmlx -Ilmlx -lXext -lX11


RM = rm -rf

PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)gnl/
PATH_PRINTF = $(PATH_SRC)ft_printf/

PATH_OBJS = ./objs/

SRC =	$(PATH_SRC)main.c\
		$(PATH_SRC)ft_bzero.c\
		$(PATH_SRC)check_extension.c\
		$(PATH_SRC)map_validation.c\
		$(PATH_SRC)maps_utils.c\
		$(PATH_SRC)movement.c\
		$(PATH_SRC)render.c\
		$(PATH_SRC)init.c\
		$(PATH_SRC)kill_window.c\
		$(PATH_SRC)ft_itoa.c\
		$(PATH_GNL)get_next_line_utils.c\
		$(PATH_GNL)get_next_line.c\
		$(PATH_PRINTF)ft_printf.c\
		$(PATH_PRINTF)ft_printf_utils.c\
		$(PATH_PRINTF)ft_ptr.c\
		$(PATH_PRINTF)ft_to_hex.c\

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)gnl/
	@mkdir -p $(PATH_OBJS)ft_printf/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re