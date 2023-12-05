NAME = libftprintf.a

SRC = ft_printf.c ft_hex.c ft_printable.c ft_putnbr.c
OBJ = $(SRC:.c=.o)
cc = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re