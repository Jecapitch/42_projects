# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 15:50:40 by jpiscice          #+#    #+#              #
#    Updated: 2025/08/26 19:32:45 by jpiscice         ###   ########.fr        #
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
						main init line_struct \
						line_read \
						split_line \
						parse_check_quotes parse_check_bs parse_check_pipes \
						parse_strip parse_flags parse_flags_helpers \
						parse_escape parse_redirect \
						var_read var_handling var_free \
						environ history \
						cmd_process cmd_build cmd_path substitue \
						pipes redirect heredoc exec \
						signals fd misc \
						end \
				) \
				$(addprefix $(BUILDIR)/, \
						echo \
						cd \
						pwd \
						env \
						export \
						unset \
						exit \
				) \
			)

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC		=	gcc
OPTIM	=	-Ofast

LIBLINK	= -L$(LFTDIR)/ -lft -lreadline

ifeq ($(OS),Darwin)
	OPTIM	= -O3 -ffast-math
	LIBLINK += -L .brew/opt/readline/lib -I .brew/opt/readline/include
endif

LINK	=	$(LIBLINK)

CFLAGS += $(OPTIM) -fcommon -Wall -Wextra -Werror \
			-Wno-error=unused-result -Wno-unused-result #-g #-fsanitize=address

CPPFLAGS += -MMD -MP -I$(INCDIR) -I$(LFTDIR)/include -I/usr/include

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@cc $(SRC) $(CFLAGS) $(CPPFLAGS) $(LINK) -o $(NAME)
	@mkdir -p /usr/local/bin/
	@echo ""
#	@sudo cp $(NAME) /usr/local/bin/
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
	@rm -f supp.supp

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
