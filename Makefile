SRCS =	src/main.c

OBJ =	$(SRC:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT = src/libs/libft/libft.a

MLX = src/libs/mlx/libmlx.a

RM = rm -f

NAME = cub3d

$(NAME): $(SRCS)
	make -s -C src/libs/libft
	make -s -C src/libs/mlx
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)
	@echo "Created"

all: $(NAME)

clean:
	@cd src/libs/libft && make -s clean
	@cd src/libs/mlx && make -s clean
	@$(RM)
	@echo "clean"

fclean: clean
	@cd src/libs/libft && make -s fclean
	@$(RM) $(NAME)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
