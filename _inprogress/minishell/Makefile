# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2025/06/27 22:59:48 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	=	/bin/bash
OS		=	$(shell uname)

NAME	=	minishell

SRCDIR	=	src
BUILDIR	=	builtin
LIBDIR	=	lib
OBJDIR	=	obj
INCDIR	=	include
LFTNAME	=	libft.a
LFTDIR	=	$(LIBDIR)/libft
LFT		=	$(LFTDIR)/$(LFTNAME)
LIBS	=	$(LFT)

SRC		= 	$(addsuffix .c, \
				$(addprefix $(SRCDIR)/, \
						main init parse \
						var var2 \
						path \
						history oldpwd \
						end \
				) \
				$(addprefix $(BUILDIR)/, \
						cd \
						pwd \
						echo \
						exit \
						env \
				) \
			)

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC		=	gcc
OPTIM	=	-Ofast

LIBLINK	= -L$(LFTDIR)/ -lft -lreadline

ifeq ($(OS),Darwin)
	CC		= clang
	OPTIM	= -O3 -ffast-math
endif

LINK	=	$(LIBLINK)

CFLAGS += $(OPTIM) -fcommon -Wall -Wextra -Werror \
			-Wno-error=unused-result -Wno-unused-result -g

CPPFLAGS += -MMD -MP -I$(INCDIR) -I$(LFTDIR)/include -I/usr/include

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@cc $(SRC) $(CFLAGS) $(CPPFLAGS) $(LINK) -o $(NAME)
	@echo ""
	@echo "$(NAME) OK"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR) $(OBJDIR)/$(BUILDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "\033[1;46m \033[0m"

$(LFT):
	@make -C $(LFTDIR)
	@echo "$(LFTNAME) OK"

clean: oclean
	@make -C $(LFTDIR) clean
	@echo "Object files deleted"

oclean:
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR) $(NAME).d*

fclean: clean
	@echo "Deleting libraries..."
	@make -C $(LFTDIR) fclean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)*
	@echo "$(NAME) deleted"

re: fclean all

bonus: all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean oclean fclean re bonus
