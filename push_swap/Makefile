# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/03/31 12:09:20 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC = main.c parse_args.c utils/constructors.c utils/t_stack.c utils/t_stack_ab_reverse.c utils/destructors.c utils/t_list.c utils/t_stack_ab_push_swap.c utils/t_stack_ab_rotate.c
OBJS = $(SRC:.c=.o)

SUBS = libft ft_printf
ARCS = $(foreach d,$(SUBS),$(d)/$(d:ft_%=libft%).a)

all:
	$(foreach d, $(SUBS), make -C $(d);)
	make $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME)

clean:
	$(foreach d, $(SUBS), make -C $(d) fclean;)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all