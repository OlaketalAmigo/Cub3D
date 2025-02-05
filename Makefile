NAME = cub3D
NAME_BONUS = cub3D_bonus

SOURCES_DIR = SOURCES/
SOURCES_DIR2 = SOURCES_BONUS/
INCLUDES_DIR = INCLUDES/
OBJECTS_DIR = OBJECTS/
OBJECTS_DIR2 = OBJECTS_BONUS/
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

SOURCES_BONUS = \
	$(SOURCES_DIR2)main.c \
	$(SOURCES_DIR2)parser.c \
	$(SOURCES_DIR2)parser_utils.c \
	$(SOURCES_DIR2)parser_utils_2.c \
	$(SOURCES_DIR2)parser_utils_3.c \
	$(SOURCES_DIR2)parser_utils_4.c \
	$(SOURCES_DIR2)parser_utils_5.c \
	$(SOURCES_DIR2)get_next_line.c \
	$(SOURCES_DIR2)get_next_line_utils.c \
	$(SOURCES_DIR2)free.c \
	$(SOURCES_DIR2)trim.c \
	$(SOURCES_DIR2)tools_1.c \
	$(SOURCES_DIR2)tools_2.c	\
	$(SOURCES_DIR2)init_data.c \
	$(SOURCES_DIR2)raycasting.c \
	$(SOURCES_DIR2)dda_algo.c \
	$(SOURCES_DIR2)wall_tex.c \
	$(SOURCES_DIR2)change_pos.c \
	$(SOURCES_DIR2)error.c

OBJECTS = $(SOURCES:$(SOURCES_DIR)%.c=$(OBJECTS_DIR)%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:$(SOURCES_DIR2)%.c=$(OBJECTS_DIR2)%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INC	=	-I INCLUDES/\
		-I ./minilibx-linux/

all: $(MLX) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(INC) $(MLX) -lXext -lX11 -lm

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $@ $(INC) $(MLX) -lXext -lX11 -lm

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJECTS_DIR2)%.o: $(SOURCES_DIR2)%.c
	@mkdir -p $(OBJECTS_DIR2)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(MLX):
	make -sC $(MLX_PATH)

bonus:	fclean $(MLX) $(NAME_BONUS)

clean:
	@rm -rf $(OBJECTS_DIR) $(OBJECTS_DIR2)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@clear

re: fclean all

.PHONY: all bonus clean fclean re
