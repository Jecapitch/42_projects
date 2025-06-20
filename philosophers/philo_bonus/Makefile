# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2025/06/20 07:44:11 by jpiscice         ###   ########.fr        #
#    Updated: 2025/01/04 23:48:54 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/bash
OS		=	$(shell uname)

NAME	=	philo_bonus

SRCDIR	=	src
LIBDIR	=	lib
OBJDIR	=	obj
INCDIR	=	include

SRC		= 	$(addprefix $(SRCDIR)/, $(addsuffix .c, main parse util init \
			timestamp sem process thread routine simulation end))

OBJ		= 	$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC		= 	gcc
OPTIM	=	-Ofast

ifeq ($(OS),Darwin)
	CC		= clang
	OPTIM	= -O3 -ffast-math
endif

CFLAGS += $(OPTIM) -Wall -Wextra -Werror \
			-Wno-error=unused-result -Wno-unused-result

CPPFLAGS += -MMD -MP -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(SRC) $(CFLAGS) $(CPPFLAGS) -lpthread -o $(NAME)
	@echo ""
	@echo "$(NAME) OK"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "\033[1;46m \033[0m"

clean: oclean

oclean:
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR) $(NAME).d*
	@echo "Object files deleted"

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)*
	@echo "$(NAME) deleted"

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean oclean fclean re
