# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:27:19 by dowon             #+#    #+#              #
#    Updated: 2023/05/22 23:20:01 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a

INC_DIR = inc

SRC_DIR = src
SRC = ft_printf.c ft_put.c ft_putbase.c ft_str.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS_DIR = ./obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ -I $(CURDIR)

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	ar cr $@ $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all