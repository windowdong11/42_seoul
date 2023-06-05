# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:13:17 by dowon             #+#    #+#              #
#    Updated: 2023/06/02 15:46:24 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g
# LEAKS = -fsanitize=address

NAME = fdf
BONUS_NAME = fdf

# ------SETTINGS------
# build directory settings
SETTING_SRC_DIR = ./src
SETTING_OBJ_DIR = ./obj

# <SRCS>
SETTING_SRCS = fdf_obj/fdf_3d.c            vector3d/scalar_op.c\
mlx_utils/init.c            vector3d/structor.c\
mlx_utils/render.c          vector3d/unit_op.c\
utils/colors.c              vector3d/vector_op.c\
vector3d/len_op.c
OBJ_SUBDIR = $(addprefix $(SETTING_OBJ_DIR)/, $(sort $(dir $(SETTING_SRCS))))
SETTING_SRCS_PATH = $(addprefix $(SETTING_SRC_DIR)/, $(dir $(SETTING_SRCS)))
SETTING_SRCS_MANDATORY = main.c
SETTING_SRCS_BONUS = main.c draw8way.c
# <LIBS>
SETTING_LIBS = libft ft_printf get_next_line smart_ptr
SETTING_FULL_LIBS = $(foreach library, $(SETTING_LIBS), ./libft/$(library)/$(addsuffix $(patsubst lib%,%,$(library:ft_%=ft%)), lib).a)
SETTING_LIBS_PATH = $(dir $(SETTING_FULL_LIBS))
SETTING_LIBS_NAME = $(notdir $(SETTING_FULL_LIBS))
# ------EXTERNAL_SETTINGS------
EXT_SETTING_MAKE_DIRS = 
EXT_SETTING_LIBS = ./MLX42/build/libmlx42.a ./MLX42/build/_deps/glfw-build/src/libglfw3.a
# cc -Wall -Wextra -Werror    obj/mlx_utils/init.o obj/mlx_utils/render.o obj/utils/colors.o obj/main.o -I./libft/libft/ -I./libft/ft_printf/ -I./libft/get_next_line/ -I./MLX42/include -lft -lftprintf -lget_next_line -lmlx42 -L./libft/libft/ -L./libft/ft_printf/ -L./libft/get_next_line/ -L./MLX42/build/ ./MLX42/build/_deps/glfw-build/src/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -o fdf
# /Users/dowon/.brew/lib/glfw
EXT_SETTING_INCLUDES = ./MLX42/include
EXT_SETTING_LIBS_DEFAULT = dl pthread m
EXT_SETTING_LIBS_PATH = $(dir $(EXT_SETTING_LIBS))
EXT_SETTING_LIBS_NAME = $(notdir $(EXT_SETTING_LIBS))
EXT_CLEAR_PATH = ./MLX42/build
# ------NOT_SETTING DONT TOUCH------
ifdef __BONUS__
	SRCS = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
else
	$(NAME) = $(BONUS_NAME)
	SRCS = $(SETTING_SRCS) $(SETTING_SRCS_BONUS)
endif
LIBS_INCLUDE_PATH = $(addprefix -I, $(SETTING_LIBS_PATH) $(EXT_SETTING_INCLUDES))
LIBS_LINK_PATH = $(addprefix -L, $(SETTING_LIBS_PATH) $(EXT_SETTING_LIBS_PATH))
LIBS_LINK =  $(addprefix -l, $(SETTING_LIBS_NAME:lib%.a=%) $(EXT_SETTING_LIBS_NAME:lib%.a=%))
SRC_NAMES = $(SETTING_SRCS) $(SETTING_SRCS_MANDATORY)
LIB_MAKE_DIRS = $(SETTING_LIBS_PATH) $(EXT_SETTING_MAKE_DIRS)
OBJS = $(addprefix $(SETTING_OBJ_DIR)/, $(SRCS:.c=.o))

# -I<header_path>
# -L<library_path>
# -l<library_name>

bonus: $(NAME)
	make __BONUS__=1 all

all: $(NAME)

$(SETTING_OBJ_DIR)/%.o: $(SETTING_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $(DEBUG) $(LEAKS) -o $@ $(LIBS_INCLUDE_PATH) $^
#  cc compile_options [options] main.c <lib dir (-L)> <libs (-l)> <header dir (-I)> <objs>

$(OBJS) : | $(SETTING_OBJ_DIR)/ $(OBJ_SUBDIR)

$(SETTING_OBJ_DIR) :
	mkdir $@

$(OBJ_SUBDIR):
	$(foreach dir, $@, mkdir $(dir);)

$(NAME) : $(OBJS)
	cmake ./MLX42 -B ./MLX42/build && make  -C ./MLX42/build -j4
	$(foreach lib_path, $(LIB_MAKE_DIRS), make -C $(lib_path);)
	$(CC) $(CFLAGS) -framework Cocoa -framework OpenGL -framework IOKit $(DEBUG) $(LEAKS) $^ $(LIBS_INCLUDE_PATH) $(LIBS_LINK) $(LIBS_LINK_PATH)  -o $@

clean:
	$(foreach lib_path, $(LIB_MAKE_DIRS), make fclean -C $(lib_path);)
	$(foreach d, $(EXT_CLEAR_PATH), rm -rf $(d);)
	rm -rf $(SETTING_OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re clean fclean all bonus
