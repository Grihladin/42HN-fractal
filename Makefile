# Variables
CC = cc
NAME = fract-ol
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude -IMLX42/include
FT_PRINTF_DIR = printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
GLFW_LIB = -lglfw -L"/opt/homebrew/opt/glfw/lib/"
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

$(NAME): $(OBJ) $(FT_PRINTF) $(MLX42_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(MLX42_LIB) $(INCLUDE) $(GLFW_LIB) -framework Cocoa -framework OpenGL -framework IOKit

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42_LIB):
	@echo "Building MLX42..."
	@cd $(MLX42_DIR) && cmake -B build && cmake --build build --parallel

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
