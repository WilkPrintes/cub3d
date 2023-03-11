# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 01:35:58 by bmugnol-          #+#    #+#              #
#    Updated: 2023/03/11 15:49:03 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# GENERAL OPTIONS
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:=	cub3D

# Master header (includes all headers)
H_MASTER	:=	master.h
# Headers
HEADER_DIR	:=	header
HEADER		:=	cub3d.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src
SRC			:=	cub3d.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled master header
C_HEADER	:=	$(H_MASTER:%.h=$(OBJ_DIR)/%.h.gch)
C_INCLUDE	:=	$(addprefix -include-pch , $(C_HEADER))

# LIBFT
LIBFT_DIR	:=	./libraries/libft
LIBFT_H_INC	:=	-I$(LIBFT_DIR)
LIBFT		:=	$(LIBFT_DIR)/libft.a

# <mlx.h> library
MLX_LIB_INC	:=	-lmlx -lXext -lX11

# <math.h> library
MATH_LIB_INC:=	-lm

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(LIBFT_H_INC)
LIB_INCLUDE	:=	$(MLX_LIB_INC) $(MATH_LIB_INC)

# Development flag: set dev=1 to automatically find .c's and .h's
ifeq ($(dev), 1)
CFLAGS		+=	-g
SRC			:= 	$(shell find src -name '*.c' -type f)
SRC_DIR		:=	$(dir $(SRC))
SRC			:=	$(notdir $(SRC))
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
HEADER		:=	$(shell find . -name '*.h' -type f)
H_INCLUDE	:=	$(sort $(addprefix -I, $(dir $(HEADER))))
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(LIBFT_H_INC)
endif

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)


# -----------------------RULES------------------------------------------------ #
.PHONY: all vg leaks norm norma clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(INCLUDE) $(LIB_INCLUDE)
	@echo "\033[0;32mCub3d created ヽ(^o^)ノ \033[0m"

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Header precompiling
$(C_HEADER): $(OBJ_DIR)/%.h.gch: %.h $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT_H_INC) $(H_INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Libft compiling
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Run program using valgrind
vg leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/map1.cub

# Norm: checks code for norm errors
norm norma:
	@norminette | grep "Error" | cat
	@$(MAKE) -C $(LIBFT_DIR) norm

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR)
#	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: removes objects' directory and generated programs
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mCub3d deleted (⌣́ _⌣̀ ) \033[0m"
#	$(MAKE) -C $(LIBFT_DIR) fclean

# Remake: full cleans and runs 'all' rule
re: fclean all
