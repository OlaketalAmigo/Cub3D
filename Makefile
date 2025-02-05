# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehe <hehe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:38:38 by tfauve-p          #+#    #+#              #
#    Updated: 2025/02/02 02:11:02 by hehe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES_DIR = SOURCES/
INCLUDES_DIR = INCLUDES/
OBJECTS_DIR = OBJECTS/
MLX_PATH = minilibx-linux/
M_NAME = libmlx.a
MLX = $(MLX_PATH)$(M_NAME)

SOURCES = \
	$(SOURCES_DIR)main.c \
	$(SOURCES_DIR)parser.c \
	$(SOURCES_DIR)parser_utils.c \
	$(SOURCES_DIR)parser_utils_2.c \
	$(SOURCES_DIR)parser_utils_3.c \
	$(SOURCES_DIR)parser_utils_4.c \
	$(SOURCES_DIR)parser_utils_5.c \
	$(SOURCES_DIR)get_next_line.c \
	$(SOURCES_DIR)get_next_line_utils.c \
	$(SOURCES_DIR)free.c \
	$(SOURCES_DIR)trim.c \
	$(SOURCES_DIR)tools_1.c \
	$(SOURCES_DIR)tools_2.c	\
	$(SOURCES_DIR)init_data.c \
	$(SOURCES_DIR)raycasting.c \
	$(SOURCES_DIR)dda_algo.c \
	$(SOURCES_DIR)wall_tex.c \
	$(SOURCES_DIR)change_pos.c \
	$(SOURCES_DIR)error.c

OBJECTS = $(SOURCES:$(SOURCES_DIR)%.c=$(OBJECTS_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INC	=	-I INCLUDES/\
		-I ./minilibx-linux/

all: $(MLX) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OBJS) -o $@ $(INC) $(MLX) -lXext -lX11 -lm

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(MLX):
	make -sC $(MLX_PATH)

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@clear

re: fclean all

.PHONY: all bonus clean fclean re
