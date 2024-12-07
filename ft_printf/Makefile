# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 00:13:05 by jpiscice          #+#    #+#              #
#    Updated: 2024/12/07 23:50:58 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LFTDIR = libft

LIBFT = $(LFTDIR)/libft.a

SRC = $(addprefix ft_, $(addsuffix .c, printf printf_format printf_utils))

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

CPPFLAGS += -I libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "####### MAKING $(NAME) #######"
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

lib: $(LIBFT)

$(LIBFT):
	@echo "####### MAKING $(LIBFT) #######"
	@cd $(LFTDIR) ; make

clean:
	@echo "####### Deleting object files #######"
	@cd $(LFTDIR) ; make clean
	@rm -f $(OBJ)

fclean: clean
	@echo "####### Deleting libraries #######"
	@rm -f $(NAME) $(LIBFT)

re: fclean all

bonus: all

.PHONY: all clean fclean re lib bonus
