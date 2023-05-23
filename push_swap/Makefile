# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:04:03 by dowon             #+#    #+#              #
#    Updated: 2023/05/23 20:00:33 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
# DEBUG = -g
# LEAKS = -fsanitize=address

NAME = push_swap
BONUS_NAME = checker

# build directory settings
SRC_DIR = ./src
OBJ_DIR = ./obj
ARC_DIR = ./libft

# common settings
COMMON_SRCS = error_handler.c	parse_args.c                    utils/t_dbl_list_swap.c \
get_merge_func.c                sorted.c                        utils/t_stack_ab_push_swap.c \
utils/compare.c                 utils/t_stack_ab_reverse.c \
manual_sort_double.c            utils/constructors.c            utils/t_stack_ab_rotate.c \
manual_sort_single.c            utils/destructors.c             utils/t_stack_push_swap.c \
manual_sort_triple.c            utils/optimize.c                utils/t_stack_rotate.c \
merge_sort.c                    utils/t_dbl_list.c \
merge.c                         utils/stack_ab_getter.c         utils/visualizer.c

COMMON_OBJ_DIRS = utils
COMMON_ARC_NAMES = libft ft_printf get_next_line
COMMON_INCLUDE_DIRS = ./include $(foreach d, $(COMMON_ARC_NAMES), $(ARC_DIR)/$(d)/include)

# mandatory setting
MANDATORY_ADDITIONAL_SRCS = main.c
MANDATORY_ADDITIONAL_INCLUDE_DIR = 
MANDATORY_ADDITIONAL_ARC_NAMES = 
MANDATORY_ADDITIONAL_OBJ_DIRS = 
# bonus setting
BONUS_ADDITIONAL_SRCS = checker_bonus.c
BONUS_ADDITIONAL_INCLUDE_DIR = 
BONUS_ADDITIONAL_ARC_NAMES = 
BONUS_ADDITIONAL_OBJ_DIRS = 


# mandatory objs
MANDATORY_OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(COMMON_OBJ_DIRS) $(MANDATORY_ADDITIONAL_OBJ_DIRS))
MANDATORY_SRCS = $(COMMON_SRCS) $(MANDATORY_ADDITIONAL_SRCS)
MANDATORY_OBJS = $(addprefix $(OBJ_DIR)/, $(MANDATORY_SRCS:.c=.o))
# mandatory includes
MANDATORY_INCLUDE_DIRS = $(COMMON_INCLUDE_DIRS) $(MANDATORY_ADDITIONAL_INCLUDE_DIR)
MANDATORY_INCLUDE = $(addprefix -I, $(MANDATORY_INCLUDE_DIRS))
# mandatory libraries
MANDATORY_ARC_NAMES = $(COMMON_ARC_NAMES) $(MANDATORY_ADDITIONAL_ARC_NAMES)
MANDATORY_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(MANDATORY_ARC_NAMES))
MANDATORY_ARCS = $(foreach d,$(MANDATORY_ARC_NAMES),$(ARC_DIR)/$(d)/$(d:ft_%=libft%).a)

# bonus objs
BONUS_OBJ_DIRS = $(addprefix $(SRC_DIR)/, $(COMMON_OBJ_DIRS) $(BONUS_ADDITIONAL_OBJ_DIRS))
BONUS_SRCS = $(COMMON_SRCS) $(BONUS_ADDITIONAL_SRCS)
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))
# bonus includes
BONUS_INCLUDE_DIRS = $(COMMON_INCLUDE_DIRS) $(BONUS_ADDITIONAL_INCLUDE_DIR)
BONUS_INCLUDE = $(addprefix -I, $(BONUS_INCLUDE_DIRS))
# bonus libraries
BONUS_ARC_NAMES = $(COMMON_ARC_NAMES) $(BONUS_ADDITIONAL_ARC_NAMES)
BONUS_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(BONUS_ARC_NAMES))
BONUS_ARCS = $(foreach d,$(BONUS_ARC_NAMES),$(ARC_DIR)/$(d)/$(d:ft_%=libft%).a)

# bonus and mandatory arcs (for cleaning)
ALL_ARC_NAMES = $(COMMON_ARC_NAMES) $(MANDATORY_ADDITIONAL_ARC_NAMES) $(BONUS_ADDITIONAL_ARC_NAMES)
ALL_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(ALL_ARC_NAMES))

all: $(NAME)

bonus: $(BONUS_NAME)

$(ARC_DIR)/%.a:
	make -C $(dir $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(MANDATORY_INCLUDE)

$(MANDATORY_OBJS): | $(MANDATORY_OBJ_DIRS)

$(BONUS_OBJS): | $(BONUS_OBJ_DIRS)

$(OBJ_DIR)/%:
	mkdir -p $@

$(BONUS_NAME): $(BONUS_ARCS) $(BONUS_OBJS)
	$(CC) $(LEAKS) $(DEBUG) $(CFLAGS) $(BONUS_OBJS) $(BONUS_ARCS) -o $(BONUS_NAME)

$(NAME): $(MANDATORY_ARCS) $(MANDATORY_OBJS)
	$(CC) $(LEAKS) $(DEBUG) $(CFLAGS) $(MANDATORY_OBJS) $(MANDATORY_ARCS) -o $(NAME)

clean:
	$(foreach d, $(ALL_ARC_DIRS), make -C $(d) fclean;)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re clean fclean all bonus