# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/12 13:50:39 by jpiscice         ###   ########.fr        #
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
		lstsize lstlast lstnew lstadd_front \
		lstadd_back lstdelone lstclear \
		lstiter lstmap \
		get_next_line))

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@ar rcs $@ $(OBJ)
	@echo "$(NAME) OK"
	
%.o: %.c
	@printf "%c" '*'
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re
