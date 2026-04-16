# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2026/04/16 02:51:08 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	libft.a
COLORNAME	=	\033[1;31m$(NAME)\033[0m

SRCDIR		=	src
INCDIR		=	include
OBJDIR		=	obj

SRC = 	$(addprefix $(SRCDIR)/ft_, $(addsuffix .c, \
				absval \
				case \
				count_words \
				fill_line \
				fprintf \
				free \
				get_next_line \
				getenv \
				getpid \
				isalnum \
				isascii \
				isset \
				itoa \
				list_circ_del \
				list_circ_display \
				list_circ_utils \
				list_circ \
				list_deq_del \
				list_deq_display \
				list_deq_utils \
				list_deq \
				list_del \
				list_display \
				list_utils \
				list \
				log \
				ltostr \
				malloc \
				mean \
				memchr \
				memcmp \
				memcpy \
				memset \
				number_len \
				power \
				print_tab \
				printf_format \
				printf_utils \
				printf \
				putnbr \
				puts \
				reverse_tab \
				split \
				sqrt \
				str_iter \
				strchr \
				strdup \
				strjoin \
				strlen \
				strncmp \
				strnstr \
				strtol \
				strtrim \
				sum \
		))

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC = cc
ifeq ($(UNAME),FreeBSD)
	CC = clang
endif

CFLAGS += -O3 -ffast-math -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo ""
	@echo "$(COLORNAME) successfully compiled"
	
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "\033[1;46m \033[0m"

clean: 
	@rm -rf $(OBJDIR)

fclean: clean
	@if [ -e $(NAME) ]; then \
		echo "Deleting $(COLORNAME)..."; \
		rm -f $(NAME) *.d; \
		echo "$(COLORNAME) deleted"; \
	fi

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re
