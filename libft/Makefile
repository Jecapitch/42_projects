# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/15 23:48:49 by jpiscice         ###   ########.fr        #
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
		free_all putnbr_fd strtrim \
		intlen putstr_fd substr \
		isalnum split tolower \
		isalpha strchr toupper \
		isascii strdup \
		isdigit striteri \
		isprint memchr strjoin \
		isset memcmp strlcat putunbr_fd uintlen \
		ltostr isupper islower ullen count_seq \
		list1_main list1_del list1_compute \
		list2_main list2_del list2_compute \
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
	@echo "Deleting object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re compile_msg
