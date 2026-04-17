# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2026/04/17 14:12:31 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash
OS			=	$(shell uname)

NAME		=	$(FT)_tester
COLORNAME	=	\033[1;31m$(NAME)\033[0m

SRCDIR		=	src
INCDIR		=	include
OBJDIR		=	obj
LFTDIR		=	libft
LFT			= 	$(LFTDIR)/libft.a

SRC = 	$(SRCDIR)/$(FILE).c

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC	= cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)/ -I$(LFTDIR)/

LINK	= -L$(LFTDIR) -lft
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

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)*

libclean:
	@make -C $(LFTDIR) fclean > /dev/null

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean libclean re
