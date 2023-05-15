# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/05/15 12:20:06 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

BASE_SRC = parse_args.c                    utils/t_dbl_list_swap.c \
get_merge_func.c                sorted.c                        utils/t_stack_ab_push_swap.c \
utils/compare.c                 utils/t_stack_ab_reverse.c \
manual_sort_double.c            utils/constructors.c            utils/t_stack_ab_rotate.c \
manual_sort_single.c            utils/destructors.c             utils/t_stack_push_swap.c \
manual_sort_triple.c            utils/optimize.c                utils/t_stack_rotate.c \
merge_sort.c                    utils/t_dbl_list.c \
merge.c                         utils/stack_ab_getter.c         utils/visualizer.c
SRC = $(BASE_SRC) main.c
OBJS = $(SRC:.c=.o)
BONUS_SRC = $(BASE_SRC) checker.c
BONUS_OBJS = $(BONUS_SRC:.c=.o)

ARC_DIRS = libft ft_printf ft_get_next_line
ARCS = $(foreach d,$(ARC_DIRS),$(d)/$(d:ft_%=libft%).a)

all:
	$(foreach d, $(ARC_DIRS), make -C $(d);)
	make $(NAME)

bonus:
	$(foreach d, $(ARC_DIRS), make -C $(d);)
	make $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(ARCS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(ARCS)
	$(CC) $(CFLAGS) $(OBJS) $(ARCS) -o $(NAME)

clean:
	$(foreach d, $(ARC_DIRS), make -C $(d) fclean;)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus $(NAME) $(NAME_BONUS)