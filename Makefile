NAME = cub3D

SOURCES_DIR = SOURCES/
INCLUDES_DIR = INCLUDES/
OBJECTS_DIR = OBJECTS/
MLX = minilibx-linux/

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
	$(SOURCES_DIR)init_player.c \
	$(SOURCES_DIR)raycasting.c \
	$(SOURCES_DIR)change_pos.c \
	$(SOURCES_DIR)error.c

OBJECTS = $(SOURCES:$(SOURCES_DIR)%.c=$(OBJECTS_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
	@clear

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(MLX) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@clear

re: fclean all

.PHONY: all bonus clean fclean re
