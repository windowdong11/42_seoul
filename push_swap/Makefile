# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/05/08 15:29:13 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

SRC = main.c  manual_sort_a_bottom.c  manual_sort_a_top.c  manual_sort_b_bottom.c  manual_sort_b_top.c  merge.c merge_data.c merge_sort_double.c  parse_args.c sorted.c utils/constructors.c utils/t_stack.c utils/t_stack_ab_reverse.c utils/destructors.c utils/t_list.c utils/t_stack_ab_push_swap.c utils/t_stack_ab_rotate.c utils/visualizer.c utils/compare.c utils/stack_ab_getter.c
OBJS = $(SRC:.c=.o)

ARC_DIRS = libft ft_printf
ARCS = $(foreach d,$(ARC_DIRS),$(d)/$(d:ft_%=libft%).a)

bonus:
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME_BONUS)

all:
	$(foreach d, $(ARC_DIRS), make -C $(d);)
	make $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(ARCS)
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME)

clean:
	$(foreach d, $(ARC_DIRS), make -C $(d) fclean;)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus