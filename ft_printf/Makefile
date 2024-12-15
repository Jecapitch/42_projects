# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/15 18:11:01 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LFTDIR = libft

LIBFT = $(LFTDIR)/libft.a

SRC = $(addprefix ft_, $(addsuffix .c, printf printf_format printf_utils))

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "\n"
	@cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)
	@echo "$(NAME) OK"

%.o: %.c
	@printf "%c" '*'
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@

lib: $(LIBFT)

$(LIBFT):
	@cd $(LFTDIR) ; make

clean:
	@echo "Deleting object files..."
	@cd $(LFTDIR) ; make clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting libraries..."
	@rm -f $(NAME) $(LIBFT)

re: fclean all

bonus: all

.PHONY: all clean fclean re lib bonus
