# Variables
CC = cc
NAME = fract-ol

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -ffast-math -flto -funroll-loops -pthread
INCLUDE = -Iinclude -IMLX42/include -Ift_printf_submodule -Iget_next_line_submodule
FT_PRINTF_DIR = ft_printf_submodule
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
GLFW_LIB = -lglfw -L"/opt/homebrew/opt/glfw/lib/"

# Dependency checking variables
BREW_EXISTS := $(shell command -v brew 2> /dev/null)
CMAKE_EXISTS := $(shell brew list cmake 2> /dev/null)
GLFW_EXISTS := $(shell brew list glfw 2> /dev/null)
GET_NEXT_LINE_DIR = get_next_line_submodule
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

# Default rule
$(NAME): $(OBJ) $(FT_PRINTF) $(MLX42_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(MLX42_LIB) $(INCLUDE) $(GLFW_LIB) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "\033[0;32m🎉 $(NAME) built successfully!\033[0m"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42_LIB):
	@echo "🔍 Checking dependencies..."
ifndef BREW_EXISTS
	@echo "❌ Error: Homebrew not found!"
	@echo "📋 Please install Homebrew first: https://brew.sh"
	@echo "💡 Run: /bin/bash -c \"\$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\""
	@exit 1
endif
ifndef GLFW_EXISTS
	@echo "📦 Installing GLFW..."
	@brew install glfw
endif
ifndef CMAKE_EXISTS
	@echo "📦 Installing CMake..."
	@brew install cmake
endif
	@echo "✅ All dependencies ready!"
	@echo "🔨 Building MLX42..."
	@cd $(MLX42_DIR) && cmake -B build && cmake --build build

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
