# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 02:10:08 by dowon             #+#    #+#              #
#    Updated: 2023/06/25 18:35:30 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libd_list.a

DEP_LIBS = smart_ptr
DEP_LIB_DIR = ..

SRC_DIR = ./src
OBJ_DIR = ./obj

SHELL_SRCS := $(shell find $(SRC_DIR) -name '*.c')
SRCS = $(SHELL_SRCS:./src/%=%)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
HEADERS = $(addprefix -I$(DEP_LIB_DIR)/, $(DEP_LIBS))


all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

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