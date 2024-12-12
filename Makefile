# Variables
CC = cc
NAME = fract-ol
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude
FT_PRINTF_DIR = printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
42LIB = libmlx42.a
GLFW_LIB = -lglfw
GET_NEXT_LINE_DIR = get_next_line
SRC_DIR = source
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/mlx_fts.c \
	$(SRC_DIR)/mandelbrot.c \
	$(SRC_DIR)/julia.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/input_validathion.c \
	$(SRC_DIR)/presets.c \
	$(GET_NEXT_LINE_DIR)/get_next_line_utils.c \
	$(GET_NEXT_LINE_DIR)/get_next_line.c
OBJ_DIR = objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)
	@echo "\033[0;32m$(NAME) built successfully!\033[0m"

$(NAME): $(OBJ) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(42LIB) $(INCLUDE) $(GLFW_LIB)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
