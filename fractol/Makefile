# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2025/04/09 13:05:52 by jpiscice         ###   ########.fr        #
#    Updated: 2025/01/04 23:48:54 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/bash
OS		=	$(shell uname)

NAME	=	fractol

SRCDIR	=	src
LIBDIR	=	lib
OBJDIR	=	obj
INCDIR	=	include
LFTNAME	=	libft.a
MLXNAME	=	libmlx_Linux.a
LFTDIR	=	$(LIBDIR)/libft
MLXDIR	=	$(LIBDIR)/minilibx
LFT		=	$(LFTDIR)/$(LFTNAME)
LIBS	=	$(LFT) $(MLX)

SRC = 	$(addprefix $(SRCDIR)/, $(addsuffix .c, main parse parse2 init fractal julia \
		chaos sierpinski hook move modify precision main_event help_event misc))

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC = gcc

LIBLINK	= -L$(LFTDIR)/ -lft -L$(MLXDIR)/ -lmlx_$(OS) -lm
XLINK	= -lXext -lX11
ifeq ($(OS),Darwin)
	CC			=	clang
	XLINK		+=	-framework Cocoa -framework OpenGL -framework IOKit
	CPPFLAGS	+=	-I /opt/X11/include
	MLXNAME		=	libmlx_Darwin.a
endif

LINK	=	$(LIBLINK) $(XLINK)
MLX		=	$(MLXDIR)/$(MLXNAME)

CFLAGS += -Ofast -Wall -Wextra -Werror -Wno-error=unused-result -Wno-unused-result -g

CPPFLAGS += -MMD -MP -I$(INCDIR) -I$(LFTDIR)/include -I$(MLXDIR) -I/usr/include

all: $(NAME)

$(NAME): $(LFT) $(MLX) $(OBJ)
	@cc $(SRC) $(CFLAGS) $(CPPFLAGS) $(LINK) -o $(NAME)
	@echo ""
	@echo "$(NAME) OK"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "\033[1;46m \033[0m"

$(LFT):
	@make -C $(LFTDIR)
	@echo "$(LFTNAME) OK"

$(MLX):
	@make -C $(MLXDIR) -f Makefile.gen
	@echo "$(MLXNAME) OK"

clean: oclean
	@make -C $(LFTDIR) clean
	@make -C $(MLXDIR) -f Makefile.gen clean
	@echo "Object files deleted"

oclean:
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR) $(NAME).d*

fclean: clean
	@echo "Deleting libraries..."
	@make -C $(LFTDIR) fclean
	@make -C $(MLXDIR) -f Makefile.gen clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)*
	@echo "$(NAME) deleted"

re: fclean all

bonus: all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean oclean fclean re bonus
