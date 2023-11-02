NAME = libftprintf.a

SRC = ft_printable.c ft_printf.c ft_num.c ft_temp.c
OBJ = $(SRC:.c=.o)
cc = gcc
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