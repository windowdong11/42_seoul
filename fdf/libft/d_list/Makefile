# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 02:10:08 by dowon             #+#    #+#              #
#    Updated: 2023/05/25 17:05:31 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libd_list.a

SRCS = d_list_constructor.c d_list_constructor_push.c d_list_find.c d_list_pop.c d_list_push.c d_list_swap.c
DEP_LIBS = smart_ptr
DEP_LIB_DIR = ..

SRC_DIR = ./src
OBJ_DIR = ./obj

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