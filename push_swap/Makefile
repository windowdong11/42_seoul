# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/05/12 22:38:34 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

SRC = utils/compare.c                 utils/t_stack_ab_push_swap.c \
main.c                          utils/constructors.c            utils/t_stack_ab_reverse.c \
manual_sort_double.c            utils/destructors.c             utils/t_stack_ab_rotate.c \
manual_sort_triple.c            utils/optimize.c                utils/t_stack_push_swap.c \
get_merge_func.c                         utils/stack_ab_getter.c         utils/t_stack_rotate.c \
parse_args.c                    utils/t_dbl_list.c              utils/visualizer.c \
sorted.c                        utils/t_dbl_list_swap.c
OBJS = $(SRC:.c=.o)

ARC_DIRS = libft ft_printf
ARCS = $(foreach d,$(ARC_DIRS),$(d)/$(d:ft_%=libft%).a)

all:
	$(foreach d, $(ARC_DIRS), make -C $(d);)
	make $(NAME)

bonus:
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME_BONUS)

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