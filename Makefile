# Variables
CC = cc
NAME = fract-ol
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
42LIB = libmlx42.a
INCLUDE = -Iinclude
GLFW_LIB = -lglfw
GLEW_PATH = -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRC = main.c \
	mlx_fts.c \
	mandelbrot.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)
	@echo "\033[0;32m$(NAME) built successfully!\033[0m"

$(NAME): $(OBJ) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(42LIB) $(INCLUDE) $(GLFW_LIB) $(GLFW_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
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
