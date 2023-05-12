NAME		=		cub3D

SRCS		=		src/main.c								\
					src/utils/colours.c						\
					src/utils/matrix_utils.c				\
					src/utils/my_mlx.c						\
					src/utils/send_msg_errors.c				\
					src/utils/utils.c						\
					src/utils/freeables.c					\
					src/validations/main/main_validations.c	\
					src/validations/map/map.c				\
					src/validations/map/map_name.c			\
					src/validations/map/utils_map.c			\
					src/validations/map/read_file.c			\
					src/validations/map/ceilling_floor.c	\
					src/validations/map/map_validations.c	\
					src/validations/map/texture.c			\
					src/validations/map/squaring_map.c		\
					src/validations/map/temp_map.c			\
					src/validations/map/map_valid.c			\
					src/exit_functions/close_game.c			\
					src/window_management/init_window.c		\
					src/window_management/load_game.c		\
					src/player/get_player_position.c		\
					src/graphics/loading_game.c				\
					src/graphics/raycasting.c				\
					src/graphics/draw_vertical_line.c		\
					src/player_movement/get_key.c			\
					src/player_movement/wasd_mov.c			\
					src/player_movement/rotate_camera.c		\
					src/graphics/mlx_handling.c				\
					src/graphics/raycasting_calcs.c			\
					src/graphics/raycasting_calcs2.c		\


HEADER 		= 		src/header/cub3d.h

OBJ_DIR		=		objects/

OBJ			=		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC			=		cc

CFLAGS		=		-g -Wall -Wextra -Werror #-fsanitize=leak

LIBFT		=		src/libs/libft/libft.a

RM			=		rm -f

RED			=		\033[0;31m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
RESET		=		\033[0m

ifeq ($(shell uname -s), Darwin)
	INCLUDES	= -framework OpenGL -framework AppKit
	MLX			= src/libs/mlx/libmlx.a
	MLX_FOLDER	= src/libs/mlx
else
	INCLUDES	= -L/usr/lib -I/src/libs/mlx_linux -lXext -lX11 -lm -lz
	MLX			= src/libs/mlx_linux/libmlx.a
	MLX_FOLDER	= src/libs/mlx_linux
endif


$(OBJ_DIR)%.o:	%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(LIBFT) -c $< -o $@

$(NAME):	$(SRCS) $(HEADER)

	@echo "$(RED)entering libft$(RESET)"
	@make -s -C src/libs/libft
	@echo "$(RED)entering mlx$(RESET)"
	@echo "$(CYAN)\tgenerate mlx ...$(RESET)"
	@make -s -C $(MLX_FOLDER)
	@echo "$(GREEN)\tlibmlx.a generated successfully!$(RESET)"
	@echo "$(RED)entering cub3D$(RESET)"
	@echo "$(CYAN)\tgenerate cub3D ...$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)generated successfully!!$(RESET)"

all: $(NAME)

run:
	make && clear && ./$(NAME) src/maps/example.cub

val:
	clear && valgrind --memcheck:leak-check=full --show-reachable=yes ./cub3D src/maps/example.cub

clean:
	@echo "$(RED)entering libft$(RESET)"
	@echo "$(MAGENTA)\tCleaning .o ...$(RESET)"
	@cd src/libs/libft && make -s clean
	@echo "$(GREEN)\tDone!$(RESET)"
	@echo "$(RED)entring mlx$(RESET)"
	@cd $(MLX_FOLDER) && make -s clean
	@echo "$(GREEN)\tlibmlx.a deleted!$(RESET)"
	@$(RM)

fclean: clean
	@echo "$(RED)entering libft$(RESET)"
	@cd src/libs/libft && make -s fclean
	@$(RM) $(NAME)
	@$(RM) -r $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
