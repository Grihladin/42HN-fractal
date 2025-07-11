# Variables
CC = cc
NAME = fract-ol

CFLAGS = -Wall -Wextra -Werror -O3 -march=native -ffast-math -flto -funroll-loops -pthread
INCLUDE = -Iinc -IMLX42/include -Ift_printf_submodule/inc -Iget_next_line_submodule/inc
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
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/mlx_fts.c \
	$(SRC_DIR)/mandelbrot.c \
	$(SRC_DIR)/julia.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/input_validathion.c \
	$(SRC_DIR)/presets.c \
	$(GET_NEXT_LINE_DIR)/src/get_next_line_utils.c \
	$(GET_NEXT_LINE_DIR)/src/get_next_line.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: init_submodules $(NAME)

# Initialize submodules if they're not already initialized
init_submodules:
	@if [ ! -f $(FT_PRINTF_DIR)/inc/ft_printf.h ] || [ ! -f $(GET_NEXT_LINE_DIR)/inc/get_next_line.h ] || [ ! -d $(MLX42_DIR)/include ]; then \
		echo "🔄 Initializing submodules..."; \
		git submodule update --init --recursive; \
		echo "✅ Submodules initialized!"; \
	fi

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
	@if [ -d $(FT_PRINTF_DIR) ]; then $(MAKE) -C $(FT_PRINTF_DIR) clean; fi
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	@rm -f $(NAME)
	@if [ -d $(FT_PRINTF_DIR) ]; then $(MAKE) -C $(FT_PRINTF_DIR) fclean; fi

re: fclean all

.PHONY: all clean fclean re init_submodules
