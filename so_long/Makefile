NAME := so_long

CC := cc
RM := rm -f

CLINKS		= -ldl -lglfw -pthread -lm
CFLAGS		= -g
MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= Libft
LIBFT		= $(FT)/libft.a

SOURCE := main.c read_map.c load_image.c key_hook.c letter_to_png.c collectibles.c error.c utils.c
OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)	
	$(MAKE) -C $(MLX)
	
$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:

fclean: clean
		make clean -C $(MLX)
		rm -rf $(NAME)
		rm -rf $(OBJ)

re: fclean all

.PHONY:		all bonus clear clean fclean re
