NAME		:= cub3d

CC			:= clang

CCFLAGS		:= -Wall -Wextra -Werror

HEADER_DIR	:= ./header/ ./libraries/libft

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./src/

SRC_FILE	:=	cub3d.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

LIBFT		:=	libraries/libft/libft.a

LIBFT_PATH	:=	libraries/libft

LIBFT_FLAGS	:=	-L $(LIBFT_PATH) -lft

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	@$(CC) -g $(CCFLAGS) $(SRC) -o $@ $(INCLUDE) $(LIBFT_FLAGS)
	@echo "\033[0;32mCub3d created ヽ(^o^)ノ \033[0m"

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

fclean: clean
	@make fclean -s -C $(LIBFT_PATH)
	@rm -rf $(NAME)
	@echo "\033[0;31mCub3d deleted (⌣́ _⌣̀ ) \033[0m"

clean:
	@make clean -s -C $(LIBFT_PATH)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

norma:
	@norminette ./

leaks:
	@valgrind -q --tool=helgrind ./philo 2 200 100 100

.PHONY: all fclean re