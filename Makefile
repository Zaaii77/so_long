# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 13:23:46 by lowatell          #+#    #+#              #
#    Updated: 2024/12/03 10:35:25 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

LINUX_AR = .linux/*.a
LINUX_FLAGS = -lmlx -lXext -lX11 -L .linux

MAC_AR = .macos/*.a
MAC_FLAGS = -lmlx -framework OpenGL -framework AppKit -L .macos

ifeq ($(shell uname -s), Linux)
	MLXA = $(LINUX_AR)
	FLAGS = $(LINUX_FLAGS)
else ifeq ($(shell uname -s), Darwin)
	MLXA = $(MAC_AR)
	FLAGS = $(MAC_FLAGS)
else
	MLXA = 
	FLAGS = 
endif

SRC_DIR = srcs
INCS_DIR = incs
OBJS_DIR = objs

NAME = so_long

SRCS =	main.c parsing.c map_is_valid.c moves.c move_end.c backtracking.c \
	exit.c hook.c map.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GREEN = \033[32m

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make clean -C libft --no-print-directory
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Objects files have been deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) has been deleted."

re: fclean all

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@mv libft/libft.a $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_DIR)/libft.a $(MLXA) -o $(NAME) $(FLAGS)
	@echo "$(GREEN)$(NAME) has been compiled."

.PHONY: all clean fclean re

