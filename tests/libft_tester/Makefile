# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2026/04/20 18:12:18 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash
OS			=	$(shell uname)

NAME		=	$(FT)_test
COLORNAME	=	\033[1;31m$(NAME)\033[0m

SRCDIR		=	src
INCDIR		=	include
OBJDIR		=	obj
LFTDIR		=	$(LIBFT)
LFT			= 	$(LFTDIR)/libft.a
TLIBDIR		=	tester_lib
TLFT		=	$(TLIBDIR)/libtest.a

SRC = 	$(SRCDIR)/$(FILE).c

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC	= cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)/ -I$(LFTDIR)/ -I$(TLIBDIR)

LINK	= -L$(LFTDIR) -lft -L$(TLIBDIR) -ltest
ifeq ($(OS), Linux)
	LINK += -lbsd
endif

DEF		= -D FT=$(FT) -D STD=$(STD)

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@cc $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LINK) $(DEF) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEF) -c $< -o $@

$(LFT):
	@make -C $(LFTDIR) > /dev/null
	@make -C $(TLIBDIR) > /dev/null

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
	fi

libclean:
	@make -C $(LFTDIR) fclean > /dev/null
	@make -C $(TLIBDIR) fclean > /dev/null

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean libclean re
