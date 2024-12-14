# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/13 14:33:08 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LFTDIR = libft

LIBFT = $(LFTDIR)/libft.a

SRCDIR = src

INCDIR = include

SRC = $(addprefix $(SRCDIR)/ft_, $(addsuffix .c, push_swap))

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -Ilibft -I$(INCDIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "\n"
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ)
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

.PHONY: all clean fclean re lib bonus compile_msg
