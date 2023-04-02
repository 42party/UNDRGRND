NAME		=		cub3d

SRCS		=		src/main.c					\
					src/utils/colours.c			\
					src/utils/matrix_utils.c	\
					src/utils/send_msg_errors.c	\
					src/utils/utils.c			\
					src/validations/map/map.c	\

OBJ			=		$(addprefix objects/, $(SRC:.c=.o))

OBJ_DIR		=		objects/

CC			=		cc

CFLAGS		=		-g -Wall -Wextra -Werror

LIBFT		=		src/libs/libft/libft.a

MLX			=		src/libs/mlx_linux/libmlx.a

RM			=		rm -f

RED			=		\033[0;31m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
RESET		=		\033[0m

# mac $(CC) $(CFLAGS) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)
# linux $(CC) $(CFLAGS) $(LIBFT) $(MLX)  -L/usr/lib -I/src/libs/mlx_linux -lXext -lX11 -lm -lz $(SRCS) -o $(NAME)

$(OBJ_DIR)%.o:	%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o ./objects/$(@F)

$(NAME): $(OBJ)
	@echo "$(RED)entering libft$(RESET)"
	@make -s -C src/libs/libft
	@echo "$(RED)entering mlx$(RESET)"
	@echo "$(CYAN)\tgenerate mlx ...$(RESET)"
	@make -s -C src/libs/mlx_linux
	@echo "$(GREEN)\tlibmlx.a generated successfully!$(RESET)"
	@echo "$(RED)entering cub3d$(RESET)"
	@echo "$(CYAN)\tgenerate cub3d ...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX) -L/usr/lib -I/src/libs/mlx_linux -lXext -lX11 -lm -lz $(SRCS) -o $(NAME)
	@echo "$(GREEN)generated successfully!!$(RESET)"

all: $(NAME)

clean:
	@echo "$(RED)entering libft$(RESET)"
	@echo "$(MAGENTA)\tCleaning .o ...$(RESET)"
	@cd src/libs/libft && make -s clean
	@echo "$(GREEN)\tDone!$(RESET)"
	@echo "$(RED)entring mlx$(RESET)"
	@cd src/libs/mlx_linux && make -s clean
	@echo "$(GREEN)\tlibmlx.a deleted!$(RESET)"
	@$(RM)

fclean: clean
	@echo "$(RED)entering libft$(RESET)"
	@cd src/libs/libft && make -s fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
