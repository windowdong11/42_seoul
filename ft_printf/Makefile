# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:27:19 by dowon             #+#    #+#              #
#    Updated: 2022/12/24 15:57:32 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = ft_printf.a

INC_DIR = inc

SRC_DIR = src
SRC = ft_printf.c ft_put.c ft_str.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
SRCS_OBJS = $(SRCS:.c=.o)

OBJS = $(SRCS_OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(INC_DIR)

$(NAME): $(OBJS)
	ar cr $@ $^

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all