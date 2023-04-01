NAME	=	libft.a

SRC		=	ft_isalnum.c				\
			ft_isprint.c				\
			ft_memcpy.c					\
			ft_putendl_fd.c				\
			ft_strchr.c					\
			ft_strlcat.c				\
			ft_strncmp.c				\
			ft_substr.c					\
			ft_atoi.c					\
			ft_isalpha.c				\
			ft_itoa.c					\
			ft_memmove.c				\
			ft_putnbr_fd.c				\
			ft_strdup.c					\
			ft_strlcpy.c				\
			ft_strnstr.c				\
			ft_tolower.c				\
			ft_bzero.c					\
			ft_isascii.c				\
			ft_memchr.c					\
			ft_memset.c					\
			ft_putstr_fd.c				\
			ft_striteri.c				\
			ft_strlen.c					\
			ft_strrchr.c				\
			ft_toupper.c				\
			ft_calloc.c					\
			ft_isdigit.c				\
			ft_memcmp.c					\
			ft_putchar_fd.c				\
			ft_split.c					\
			ft_strjoin.c				\
			ft_strmapi.c				\
			ft_strtrim.c				\
			ft_printf.c					\
			ft_putchar_print.c			\
			ft_putstr_print.c			\
			ft_putnbr_print.c			\
			ft_putunbr_print.c			\
			ft_hex_print.c				\
			ft_pointeraddress_print.c	\
			get_next_line.c				\
			get_next_line_utils.c		\
			ft_lstnew.c					\
			ft_lstadd_front.c			\
			ft_lstsize.c				\
			ft_lstadd_back.c			\
			ft_lstlast.c				\
			ft_lstdelone.c				\
			ft_lstclear.c				\
			ft_lstiter.c				\
			ft_lstmap.c					\

OBJ		=	$(addprefix objects/, $(SRC:.c=.o))

OBJ_DIR	=	objects/

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
RESET	=	\033[0m

$(OBJ_DIR)%.o:	%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o ./objects/$(@F)

$(NAME):	$(OBJ)
			@echo "$(BLUE)\tCreating .o ...$(RESET)"
			@echo "$(GREEN)\tDone!$(RESET)"
			@echo "$(BLUE)\tCreating libft.a$(RESET)"
				@ar rcs $(NAME) $(OBJ)
			@echo "$(GREEN)\tCreated!$(RESET)"

all:		$(NAME)

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@echo "$(MAGENTA)\tRemoving libft.a ...$(RESET)"
			@$(RM) $(NAME)
			@echo "$(GREEN)\tlibft.a deleted!$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
