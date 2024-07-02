NAME		:= so_long
INCLUDES	:= -I includes/
SRC_DIR		:= sources/
OBJ_DIR		:= objects/
LIBFT_DIR	:= libft/
PATH_MLX	:= /mlx_linux
CC			:= gcc
CFLAGS		:= -g3 -Wall -Werror -Wextra -D BUFFER_SIZE	= 1
FLAGS		:= -ldl -Imlx -L/minilibx-linux/ -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
RM			:= rm -f
SMAKE		= make --no-print-directory

END			=	\033[0m
BOLD		=	\033[1m
UNDER		=	\033[4m
REV			=	\033[7m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
LIGHT_RED	=	\033[0;31m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRC_FILES = main.c

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .c, $(SRC_FILES)))

libft:
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully!$(END)"

$(NAME): lift $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT) -lft -L$(PATH_MLX) -lmlx -lXext -lX11 -o $(NAME)

all:	${NAME}
	@echo "$(GREEN)Compilation success!$(END)"

.c.o:
	@${CC} ${CFLAGS} -Imlx -Ibass -c $< -o $@\

bonus: ${OBJS} ${OBJS_B}
	@make -C $(PATH_MLX)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L$(PATH_MLX) -lmlx $(FLAGS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@$(SMAKE) -C $(LIBFT) fclean
	@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT) fclean

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme | awk '{\
			if ($$NF == "OK!") { \
				print "$(GREEN)"$$0"$(END)" \
			} else if ($$NF == "Error!") { \
				print "$(RED)$(BOLD)"$$0"$(END)" \
			} else if ($$1 == "Error:") { \
				print "$(LIGHT_RED)"$$0"$(END)" \
			} else { print }}'

re: fclean all

.PHONY: bonus all clean fclean re