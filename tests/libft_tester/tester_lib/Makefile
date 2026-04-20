# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2026/04/20 18:08:55 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		=	libtest.a
COLORNAME	=	\033[1;31m$(NAME)\033[0m

SRCDIR		=	.
INCDIR		=	.
OBJDIR		=	.

SRC = 	$(addprefix $(SRCDIR)/ft_, $(addsuffix .c, \
				case \
				cmp \
				count_words \
				cpy \
				fprintf \
				free \
				isalnum \
				isascii \
				isset \
				itoa \
				list_del \
				list_iter \
				list \
				log \
				ltostr \
				malloc \
				memchr \
				memset \
				number_len \
				print_tab \
				printf_format \
				printf_utils \
				printf \
				putnbr \
				puts \
				reverse_tab \
				split \
				str_iter \
				strchr \
				strjoin \
				strlen \
				strtol \
				substr \
		))

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC = cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo ""
	@echo -e "$(COLORNAME) successfully compiled"
	
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -ne "\033[1;46m \033[0m"

clean: 
	@rm -rf $(OBJ)

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo -e "Deleting $(COLORNAME)..."; \
		rm -f $(NAME) *.d; \
		echo -e "$(COLORNAME) deleted"; \
	fi

re: fclean all
bonus: all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re
