NAME = ft_printf.a
SRC =	ft_printf.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_int.c \
		ft_printf_uint.c \
		ft_printf_percent.c \
		ft_printf_ptr.c \
		ft_printf_hexadecimal.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-I/path/to/headers

.PHONY: all clean fclean re

# Targets
all: $(NAME)


$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
