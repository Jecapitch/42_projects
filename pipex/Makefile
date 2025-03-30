# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2025/03/28 01:05:04 by jpiscice         ###   ########.fr        #
#    Updated: 2025/01/04 23:48:54 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/bash
OS		=	$(shell uname)

NAME	=	pipex

SRCDIR	=	src
LIBDIR	=	lib
OBJDIR	=	obj
INCDIR	=	include
LFTDIR	=	$(LIBDIR)/libft

LFT		=	$(LIBDIR)/libft.a
LIBS	=	$(LFT)

SRC = 	$(addprefix $(SRCDIR)/, $(addsuffix .c, main arg_handle path proc))

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

LINK = -L$(LIBDIR)/ -lft

ifeq ($(OS),Linux)
	CC = gcc
else
	CC = clang
endif

CFLAGS += -O3 -Wall -Wextra -Werror -Wno-error=unused-result -Wno-unused-result -g

CPPFLAGS += -MMD -MP -I$(INCDIR) -I$(LFTDIR)/include

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@cc $(SRC) $(CFLAGS) $(CPPFLAGS) $(LINK) -o $(NAME)
	@echo ""
	@echo "$(NAME) OK"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@printf "\033[1;46m \033[0m"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LFT):
	@make -C $(LFTDIR)
	@mv $(LFTDIR)/libft.a $(LIBDIR)
	@echo "$(LFT) OK"

clean: oclean
	@make -C $(LFTDIR) clean
	@echo "Object files deleted"

oclean:
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Deleting libraries..."
	@make -C $(LFTDIR) fclean
	@rm -f $(LIBS)
	@echo "Libraries deleted"
	@echo "Deleting $(NAME)..."
	@rm -rf $(NAME) $(NAME).d $(NAME).dSYM
	@echo "$(NAME) deleted"

re: fclean all

bonus: all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean oclean fclean re bonus
