# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gprunet <gprunet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:38:38 by tfauve-p          #+#    #+#              #
#    Updated: 2025/01/13 14:53:11 by gprunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES_DIR = SOURCES/
INCLUDES_DIR = INCLUDES/
OBJECTS_DIR = OBJECTS/

SOURCES = \
	$(SOURCES_DIR)main.c \
	$(SOURCES_DIR)parser.c \
	$(SOURCES_DIR)parser_utilis.c \
	$(SOURCES_DIR)init_data.c \
	$(SOURCES_DIR)init_player.c \
	$(SOURCES_DIR)raycasting.c \
	$(SOURCES_DIR)change_pos.c \
	$(SOURCES_DIR)error.c

OBJECTS = $(SOURCES:$(SOURCES_DIR)%.c=$(OBJECTS_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

PURPLE = \033[0;35m
LIGHTPURPLE = \033[1;35m
RED = \033[0;31m
LIGHTRED = \033[1;31m
ORANGE = \033[0;33m
YELLOW = \033[1;33m
LIGHTGREEN = \033[1;32m
GREEN = \033[0;32m
LIGHTCYAN = \033[1;36m
CYAN = \033[0;36m
LIGHTBLUE = \033[1;34m
BLUE = \033[0;34m
RESET = \033[0;0m

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -lreadline -lcurses
	@clear

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@clear

re: fclean all

.PHONY: all bonus clean fclean re

