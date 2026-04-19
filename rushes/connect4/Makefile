# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 23:26:59 by jepiscic          #+#    #+#              #
#    Updated: 2026/04/19 23:08:45 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /usr/bin/env bash

GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"
NC = "\033[0m"

NAME = connect4

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT = libft
INCL = include
SRC_DIR = src
SRC_FILES = main algorithm start_end display user utils

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ = ${SRC:%.c=%.o}
INC = -I$(INCL) -I$(LIBFT)
LINK = -L$(LIBFT) -lft

COLUMNS = $(shell tput cols 2>/dev/null)
LINES  = $(shell tput lines 2>/dev/null)
export COLUMNS
export LINES

.PHONY: all
all: libft $(NAME)

$(NAME): $(OBJ)
	@echo -e $(CYAN)Compiling$(NC) $@
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $@ $(LINK)
	@echo -e $(GREEN)Done$(NC)
	@export COLUMNS LINES

%.o: %.c
	@echo -e $(CYAN)Building$(NC) $<
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: libft
libft:
	@make -C $(LIBFT)

.PHONY: clean
clean:
	@echo -e $(BLUE)Cleaning$(NC) environment
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT)

.PHONY: fclean
fclean: clean
	@echo -e $(BLUE)Removing$(NC) executable
	@$(RM) $(NAME)
	@echo -e $(BLUE)Removing$(NC) archive
	@$(RM) -f libft.a
	@$(RM) -f $(LIBFT)/libft.a


.PHONY: re
re: fclean all

.PHONY: gitignore
gitignore:
	@echo -e $(CYAN)Initializing$(NC) .gitignore
	@echo ".gitignore" > .gitignore
	@echo "*.swp" >> .gitignore
	@echo ".DS_Store" >> .gitignore
	@echo ".clangd" >> .gitignore
	@echo "*.o" >> .gitignore
	@echo "*.a" >> .gitignore
	@echo "$(NAME)" >> .gitignore
