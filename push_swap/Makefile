# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/03/19 12:57:22 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = main.c valid_args.c
OBJS = $(SRC:.c=.o)

SUBS = libft ft_printf
ARCS = $(foreach d,$(SUBS),$(d)/$(d:ft_%=libft%).a)

all:
	$(foreach d, $(SUBS), make -C $(d);)
	make $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	echo $(ARCS)
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME)

clean:
	$(foreach d, $(SUBS), make -C $(d) fclean;)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all