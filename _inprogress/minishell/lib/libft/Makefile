# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 00:15:49 by jpiscice          #+#    #+#              #
#    Updated: 2025/06/26 19:52:54 by jpiscice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = 	/bin/sh

NAME = 		libft.a

SRCDIR =	src
INCDIR =	include
OBJDIR =	obj

SRC = 	$(addprefix $(SRCDIR)/ft_, $(addsuffix .c, isspace memcpy strlcpy \
		arr_reverse itoa memmove strlen \
		atoi strtol countwhile countwhile_set countwhile_condition memset strmapi \
		bzero putchar_fd strncmp \
		calloc putendl_fd strnstr \
		count_words putmnbr_fd strrchr \
		free_all free_nul putnbr_fd strtrim strstrip \
		intlen intlen_base putstr_fd substr \
		isalnum split tolower \
		isalpha strchr toupper \
		isascii strdup \
		isdigit isint striteri \
		isprint memchr strjoin \
		isset memcmp strlcat putunbr_fd uintlen \
		ltostr isupper islower ullen count_seq \
		list1 list1_del list1_utils list1_display \
		list2 list2_del list2_utils list2_display \
		list_circ list_circ_del list_circ_utils list_circ_display \
		printf fprintf printf_format printf_utils print_arr fill_line \
		get_next_line \
		getenv \
		sum mean absval power sqrt \
		std_dev))

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

CC = cc
ifeq ($(UNAME),FreeBSD)
	CC = clang
endif

CFLAGS += -O3 -Wall -Wextra -Werror -Wno-error=unused-result -Wno-unused-result -g

CPPFLAGS += -MMD -MP -I$(INCDIR)/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo ""
	
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "\033[1;46m \033[0m"

clean: 
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME) *.d
	@echo "$(NAME) deleted"

re: fclean all

.SUFFIXES:
.SUFFIXES: .c .o .a

.PHONY: all clean fclean re
