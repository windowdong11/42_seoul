# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 02:10:08 by dowon             #+#    #+#              #
#    Updated: 2023/06/14 18:40:44 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

INCLUDE_DIR = .
SRC_DIR = ./src
OBJ_DIR = ./obj

SHELL_SRCS = $(shell find $(SRC_DIR) -name '*.c')
SRC = $(SHELL_SRCS:./src/%=%)


INCLUDE = $(addprefix -I, $(INCLUDE_DIR))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar cr $@ $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all