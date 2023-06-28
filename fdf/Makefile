# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:13:17 by dowon             #+#    #+#              #
#    Updated: 2023/06/28 23:57:49 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror 
# DEBUG = -g
# LEAK_SANITIZER_DIR = /Users/dowon/Desktop/scripts/LeakSanitizer
# LFLAGS = -fsanitize=address -L$(LEAK_SANITIZER_DIR) -llsan -lc++ -Wno-gnu-include-next
# INCLUDE_LEAKS_SANITIZER = -I$(LEAK_SANITIZER_DIR)/include

NAME = fdf
BONUS_NAME = fdf

# ------SETTINGS------
# build directory settings
SETTING_SRC_DIR = ./src
SETTING_OBJ_DIR = ./obj

# <SRCS>
SHELL_SRCS := $(shell find $(SETTING_SRC_DIR) -name '*.c')
SETTING_SRCS = $(SHELL_SRCS:./src/%=%)
OBJ_SUBDIR = $(addprefix $(SETTING_OBJ_DIR)/, $(sort $(dir $(SETTING_SRCS))))
SETTING_SRCS_PATH = $(addprefix $(SETTING_SRC_DIR)/, $(dir $(SETTING_SRCS)))
SETTING_SRCS_MANDATORY = 
SETTING_SRCS_BONUS = 
# <LIBS>
SETTING_LIBS = libft ft_printf get_next_line smart_ptr d_list
SETTING_FULL_LIBS = $(foreach library, $(SETTING_LIBS), ./libft/$(library)/$(addsuffix $(patsubst lib%,%,$(library:ft_%=ft%)), lib).a)
SETTING_LIBS_PATH = $(dir $(SETTING_FULL_LIBS))
SETTING_LIBS_NAME = $(notdir $(SETTING_FULL_LIBS))
# ------EXTERNAL_SETTINGS------
EXT_SETTING_MAKE_DIRS = 
EXT_SETTING_LIBS = ./MLX42/build/libmlx42.a /Users/dowon/.brew/lib/glfw
EXT_SETTING_INCLUDES = ./MLX42/include
EXT_SETTING_LIBS_DEFAULT = dl pthread m glfw
EXT_SETTING_LIBS_PATH = $(dir $(EXT_SETTING_LIBS))
EXT_SETTING_LIBS_NAME = $(notdir $(EXT_SETTING_LIBS))
EXT_CLEAR_PATH = ./MLX42/build
# ------DO NOT EDIT NEXT LINES------
ifdef __BONUS__
	SRCS = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
else
	NAME = $(BONUS_NAME)
	SRCS = $(SETTING_SRCS) $(SETTING_SRCS_BONUS)
endif
LIBS_INCLUDE_PATH = $(addprefix -I, $(SETTING_LIBS_PATH) $(EXT_SETTING_INCLUDES)) $(INCLUDE_LEAKS_SANITIZER)
LIBS_LINK_PATH = $(addprefix -L, $(SETTING_LIBS_PATH) $(EXT_SETTING_LIBS_PATH))
LIBS_LINK =  $(addprefix -l, $(SETTING_LIBS_NAME:lib%.a=%) $(EXT_SETTING_LIBS_NAME:lib%.a=%))
SRC_NAMES = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
LIB_MAKE_DIRS = $(SETTING_LIBS_PATH) $(EXT_SETTING_MAKE_DIRS)
OBJS = $(addprefix $(SETTING_OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

bonus: all

$(SETTING_OBJ_DIR)/%.o: $(SETTING_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $(DEBUG) $(LEAKS) -o $@ $(LIBS_INCLUDE_PATH) $^
#  cc compile_options [options] main.c <lib dir (-L)> <libs (-l)> <header dir (-I)> <objs>

$(OBJS) : | $(SETTING_OBJ_DIR) $(OBJ_SUBDIR)

$(SETTING_OBJ_DIR):
	mkdir $@

$(OBJ_SUBDIR):
	$(foreach dir, $@, mkdir $(dir);)

$(NAME) : $(OBJS)
	cmake ./MLX42 -B ./MLX42/build && make  -C ./MLX42/build -j4
	$(foreach lib_path, $(LIB_MAKE_DIRS), make -C $(lib_path);)
	$(CC) $(CFLAGS) $(LFLAGS) $(DEBUG) $(LEAKS) $^ $(LIBS_INCLUDE_PATH) $(LIBS_LINK) $(LIBS_LINK_PATH) -framework Cocoa -framework OpenGL -framework IOKit -o $@

clean:
	$(foreach lib_path, $(LIB_MAKE_DIRS), make fclean -C $(lib_path);)
	$(foreach d, $(EXT_CLEAR_PATH), rm -rf $(d);)
	rm -rf $(SETTING_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re clean fclean all bonus
