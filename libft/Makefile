# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/19 23:40:39 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = 	/bin/sh

NAME = 		libft.a

SRCDIR =	src/

INCDIR =	include/

SRC = 	$(addprefix $(SRCDIR)ft_, $(addsuffix .c, isspace memcpy strlcpy \
		arr_reverse itoa memmove strlen \
		atoi countwhile countwhile_set countwhile_condition memset strmapi \
		bzero putchar_fd strncmp \
		calloc putendl_fd strnstr \
		count_words putmnbr_fd strrchr \
		free_all free_nul putnbr_fd strtrim \
		intlen putstr_fd substr \
		isalnum split tolower \
		isalpha strchr toupper \
		isascii strdup \
		isdigit isint striteri \
		isprint memchr strjoin \
		isset memcmp strlcat putunbr_fd uintlen \
		ltostr isupper islower ullen count_seq \
		list1 list1_del list1_utils \
		list2 list2_del list2_utils \
		list_circ list_circ_del list_circ_utils \
		printf printf_format printf_utils \
		get_next_line))

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)

all: compile_msg $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $@ $(OBJ)
	@echo "$(NAME) OK"
	
%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf ">"

compile_msg:
	@printf "Compiling $(NAME) "

clean: 
	@echo "Deleting $(NAME) object files..."
	@rm -f $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re compile_msg
