# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:52:56 by nthys             #+#    #+#              #
#    Updated: 2026/04/19 02:51:56 by jepiscic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /usr/bin/env bash

GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"
NC = "\033[0m"

NAME = libft.a

RM = rm -f

AR = ar rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c            \
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c                 \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c             \
	   ft_strrchr.c ft_strncmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c              \
	   ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c                  \
	   ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c ft_itoa.c                 \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putnbr_base_fd.c                                                         \
	   ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c                \
       ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c              \
	   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c                    \

FT_PRINTF_DIR = ft_printf
FT_PRINTF_FILES = ft_printf ft_args ft_padding ft_int	ft_hex ft_chars ft_utils
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR)/, $(addsuffix .c, $(FT_PRINTF_FILES)))

OBJ = ${SRCS:.c=.o} ${FT_PRINTF:.c=.o}

$(NAME): $(OBJ)
	@echo -e $(CYAN)Compiling$(NC) $@
	@$(AR) $(NAME) $(OBJ)
	@echo -e $(GREEN)Done$(NC)

%.o: %.c
	@echo -e $(CYAN)Building$(NC) $<
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo -e $(BLUE)Cleaning$(NC) environment
	@$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	@echo -e $(BLUE)Removing$(NC) archive
	@$(RM) $(NAME)

.PHONY: re
re: fclean all

