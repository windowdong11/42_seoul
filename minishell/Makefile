# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:13:17 by dowon             #+#    #+#              #
#    Updated: 2023/07/03 20:42:57 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC := cc
CFLAGS := -Wall -Wextra -Werror
# DEBUG := -g
# LEAK_SANITIZER_DIR := /Users/dowon/Desktop/scripts/LeakSanitizer
# INCLUDE_LEAKS_SANITIZER := -I$(LEAK_SANITIZER_DIR)/include
# LEAKS := -fsanitize=address -L$(LEAK_SANITIZER_DIR) -llsan -lc++ -Wno-gnu-include-next $(INCLUDE_LEAKS_SANITIZER)

# ------SETTINGS------
ACTIVE_LIBFT_LIBS := libft

NAME := minishell

# used with -l option
EXT_LINK := readline
# used with -L option
EXT_LINK_PATH := 
# used with -I option
EXT_INCLUDE_PATH := 

# build directory settings
SRC_DIR := ./src
OBJ_DIR := ./obj

# <DIRECTORY SETTINGS>
SRC_BASE_DIR := ./src
OBJ_BASE_DIR := ./obj
LIBFT_BASE_DIR := ./libft

# <SRCS_WITHOUT_SRC_DIR>
SRC_WITH_SRC_DIR := $(shell find $(SRC_DIR) -name '*.c')
SRCS_WITHOUT_SRC_DIR := $(SRC_WITH_SRC_DIR:$(SRC_DIR)/%=%)
OBJ_SUBDIR := $(addprefix $(OBJ_DIR)/, $(sort $(dir $(SRCS_WITHOUT_SRC_DIR))))

# <LIBS>
LIBS := $(foreach library, $(ACTIVE_LIBFT_LIBS), ./libft/$(library)/$(addsuffix $(patsubst lib%,%,$(library:ft_%=ft%)), lib).a)
LIBS_DIRS := $(dir $(LIBS))
LIBS_FILENAMES := $(notdir $(LIBS))

# ------DO NOT EDIT NEXT LINES------
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS_WITHOUT_SRC_DIR:.c=.o))
LINK :=  $(addprefix -l, $(LIBS_FILENAMES:lib%.a=%) $(EXT_LINK))
LINK_PATH := $(addprefix -L, $(LIBS_DIRS) $(EXT_LINK_PATH))
INCLUDE_PATH := $(addprefix -I, $(LIBS_DIRS) $(EXT_INCLUDE_PATH))

UTILS_SRC := $(shell find utils -depth 1 -name '*.c')
UTILS := $(UTILS_SRC:.c=)

all: $(NAME) $(UTILS)

$(UTILS):
	$(CC) $@.c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DEBUG) $(LEAKS) $(INCLUDE_PATH) -c $^ -o $@

$(OBJS) : | $(OBJ_DIR) $(OBJ_SUBDIR)

$(OBJ_DIR):
	mkdir $@

$(OBJ_SUBDIR):
	$(foreach dir, $@, mkdir $(dir);)

$(LIBS):
	make -C $(dir $@)

$(NAME) : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(DEBUG) $(LEAKS) $(LIBS_INCLUDE_PATH) $(LINK) $(LINK_PATH) $^ -o $@

clean_utils:
	rm -rf $(UTILS)

clean:
	$(foreach lib_path, $(LIBS_DIRS), make fclean -C $(lib_path);)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all clean_utils
