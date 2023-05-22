# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 02:10:08 by dowon             #+#    #+#              #
#    Updated: 2023/05/22 23:16:44 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c
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