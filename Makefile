SRCS =	src/main.c

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT = src/libs/libft/libft.a

MLX = src/libs/mlx/libmlx.a

RM = rm -f

NAME = cub3d

$(NAME): $(SRCS)
	make -s -C libft
	make -s -C mlx
	$(CC) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@cd libft && make clean
	@cd mlx && make clean
	$(RM)

fclean: clean
	@cd libft && make fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
