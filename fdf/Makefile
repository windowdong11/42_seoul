# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:13:17 by dowon             #+#    #+#              #
#    Updated: 2023/05/27 20:13:37 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
# DEBUG = -g
# LEAKS = -fsanitize=address

NAME = fdf
BONUS_NAME = fdf

# ------SETTINGS------
# build directory settings
SETTING_SRC_DIR = ./src
SETTING_OBJ_DIR = ./obj

# <SRCS>
SETTING_SRCS = mlx_utils/init.c mlx_utils/render.c utils/colors.c
SETTING_SRCS_PATH = $(addprefix $(SETTING_SRC_DIR)/, $(dir $(SETTING_SRCS)))
SETTING_SRCS_MANDATORY = main.c
SETTING_SRCS_BONUS = main.c
# <LIBS>
SETTING_LIBS = ./libft/libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/get_next_line/libget_next_line.a
SETTING_LIBS_PATH = $(dir $(SETTING_LIBS))
SETTING_LIBS_NAME = $(notdir $(SETTING_LIBS))
# ------EXTERNAL_SETTINGS------
EXT_SETTING_LIBS = ./MLX42/build/libmlx42.a /Users/dowon/.brew/lib/glfw
EXT_SETTING_INCLUDES = ./MLX42/include
EXT_IGNORE_LIBS = /Users/dowon/.brew/lib
EXT_SETTING_LIBS_DEFAULT = dl pthread m
EXT_SETTING_LIBS_PATH = $(dir $(EXT_SETTING_LIBS))
EXT_SETTING_LIBS_NAME = $(notdir $(EXT_SETTING_LIBS))
EXT_CLEAR_PATH = ./MLX42/build
# ------NOT_SETTING DONT TOUCH------
LIBS_INCLUDE_PATH = $(addprefix -I, $(SETTING_LIBS_PATH) $(EXT_SETTING_LIBS_PATH) $(EXT_SETTING_INCLUDES))
LIBS_LINK_PATH = $(addprefix -L, $(SETTING_LIBS_PATH) $(EXT_SETTING_LIBS_PATH))
LIBS_LINK =  $(addprefix -l, $(SETTING_LIBS_NAME:lib%.a=%) $(EXT_SETTING_LIBS_NAME:lib%.a=%))
SRC_NAMES = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
SRCS = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
OBJS = $(addprefix $(SETTING_OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(SETTING_OBJ_DIR)/%.o: $(SETTING_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $(DEBUG) $(LEAKS) -o $@ $(LIBS_INCLUDE_PATH) $^
#  cc compile_options [options] main.c <lib dir (-L)> <libs (-l)> <header dir (-I)> <objs>

$(OBJS) : | ./obj ./obj/utils ./obj/mlx_utils

./obj :
	mkdir obj

./obj/utils:
	mkdir obj/utils

./obj/mlx_utils:
	mkdir obj/mlx_utils

$(NAME) : $(OBJS)
	cmake ./MLX42 -B ./MLX42/build && make  -C ./MLX42/build -j4
	$(foreach lib_path, $($(SETTING_LIBS_PATH):$(EXT_IGNORE_LIBS)=), make -C $(lib_path);)
	$(CC) $(CFLAGS) $(DEBUG) $(LEAKS) -o $@ $(LIBS_INCLUDE_PATH) $(LIBS_LINK_PATH) $(LIBS_LINK) $^

clean:
	$(foreach d, $(ALL_ARC_DIRS), make -C $(d) fclean;)
	$(foreach d, $(EXT_CLEAR_PATH), rm -rf $(d);)
	rm -rf $(SETTING_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re clean fclean all bonus
