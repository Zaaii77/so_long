# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 13:23:46 by lowatell          #+#    #+#              #
#    Updated: 2024/11/27 23:29:42 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

ifeq ($(shell uname -s), Linux)
	MLXA = libmlx_Linux.a
else ifeq ($(shell uname -s), Darwin)
	MLXA = libmlx.a
else
	MLXA = 
endif

SRC_DIR = srcs
INCS_DIR = incs
OBJS_DIR = objs

NAME = so_long

SRCS =	main.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GREEN = \033[32m

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make clean -C libft --no-print-directory
	@mv objs/libmlx_Linux.a .libmlx_Linux.a 
	@mv objs/libmlx.a .libmlx.a 
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Objects files have been deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) has been deleted."

re: fclean all

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@mv libft/libft.a $(OBJS_DIR)
	@mv .libmlx_Linux.a objs/libmlx_Linux.a
	@mv .libmlx.a objs/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_DIR)/libft.a $(OBJS_DIR)/$(MLXA) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been compiled."

.PHONY: all clean fclean re

