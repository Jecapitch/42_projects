# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2025/03/19 11:52:46 by jpiscice         ###   ########.fr        #
#    Updated: 2025/01/04 23:48:54 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LFTDIR = libft

LIBFT = $(LFTDIR)/libft.a

SRCDIR = src

INCDIR = include

SRC = 	main.c $(addprefix $(SRCDIR)/, $(addsuffix .c, clear common error \
		getval init non_radix_ops print radix_sort rot_sort small_sort \
		sort_check))

OBJ = $(SRC:.c=.o)

CC = gcc

#CFLAGS += -Wall -Wextra -Werror -fsanitize=address
CFLAGS += -fsanitize=address

CPPFLAGS += -I$(LFTDIR)/include -I$(INCDIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "\n"
	@cc $(CFLAGS) $(CPPFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(NAME) OK"

%.o: %.c
	@printf "%c" '>'
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

lib: $(LIBFT)

$(LIBFT):
	@cd $(LFTDIR) ; make

clean: oclean
	@cd $(LFTDIR) ; make clean

oclean:
	@echo "Deleting $(NAME) object files..."
	@rm -f $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@echo "Deleting $(LIBFT)..."
	@rm -f $(LIBFT)
	@echo "$(LIBFT) deleted"
	@echo "Deleting program $(NAME)..."
	@rm -f $(NAME)
	@echo "Program $(NAME) deleted"

re: fclean all

bonus: all

.PHONY: all clean oclean fclean re lib bonus compile_msg
