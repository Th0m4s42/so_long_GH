NAME := so_long
CC := cc
FLAGS := -Wall -Werror -Wextra -g
#FLAGS := -g

MLX_INCLUDES = -I/opt/X11/include -Iminilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR := minilibx-linux/

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

SRC_DIR := sources/
OBJ_DIR := objs/

SRCS := \
	$(SRC_DIR)main.c \
	$(SRC_DIR)error1.c \
	$(SRC_DIR)error2.c \
	$(SRC_DIR)error3.c \
	$(SRC_DIR)error4.c \
	$(SRC_DIR)utils.c \

LIBFT_DIR := libft/
LIBFT_LIB := libft/libft.a
LIBFT := -L $(LIBFT_DIR) -lft
LIBFT_FLAGS := -Llibft -l:libft.a

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	make -C libft/
	make -C minilibx-linux/
	@$(CC) $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(Green)$(NAME) CREATED $(White)"

all : $(NAME)

clean :
	@make clean -C ./libft
	@make clean -C ./minilibx-linux
	@echo "$(Red)Cleaning object files...$(White)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(Red)$(NAME) DELETED $(White)"

re : fclean all

.PHONY: re clean fclean