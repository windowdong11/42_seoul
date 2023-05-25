CC = cc
CFLAGS = -Wall -Wextra -Werror 
# DEBUG = -g
# LEAKS = -fsanitize=address

NAME = fdf
BONUS_NAME = fdf

LIBMLX	= ./MLX42
LIBS	= -lmlx42 -ldl -lglfw -pthread -lm -L$(LIBMLX)/build -L/Users/dowon/.brew/lib/

# build directory settings
SRC_DIR = ./src
OBJ_DIR = ./obj
ARC_DIR = ./libft

# common settings
COMMON_OBJ_DIRS = mlx_utils utils 
COMMON_SRCS = mlx_utils/init.c mlx_utils/render.c \
utils/colors.c

COMMON_EXTERNAL_ARCS = ./MLX42/build/libmlx42.a
COMMON_ARC_NAMES = libft ft_printf get_next_line
COMMON_INCLUDE_DIRS = ./include $(LIBMLX)/include $(foreach d, $(COMMON_ARC_NAMES), $(ARC_DIR)/$(d))
# mandatory setting
MANDATORY_ADDITIONAL_SRCS = main.c
MANDATORY_ADDITIONAL_INCLUDE_DIR = 
MANDATORY_ADDITIONAL_ARC_NAMES = 
MANDATORY_ADDITIONAL_OBJ_DIRS = 
# bonus setting
BONUS_ADDITIONAL_SRCS = 
BONUS_ADDITIONAL_INCLUDE_DIR = 
BONUS_ADDITIONAL_ARC_NAMES = 
BONUS_ADDITIONAL_OBJ_DIRS = 


# mandatory objs
MANDATORY_OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(COMMON_OBJ_DIRS) $(MANDATORY_ADDITIONAL_OBJ_DIRS))
MANDATORY_SRC_DIRS = $(addprefix $(SRC_DIR)/, $(COMMON_OBJ_DIRS) $(MANDATORY_ADDITIONAL_OBJ_DIRS))
MANDATORY_SRCS = $(COMMON_SRCS) $(MANDATORY_ADDITIONAL_SRCS)
MANDATORY_OBJS = $(addprefix $(OBJ_DIR)/, $(MANDATORY_SRCS:.c=.o))
# mandatory includes
MANDATORY_INCLUDE_DIRS = $(COMMON_INCLUDE_DIRS) $(MANDATORY_ADDITIONAL_INCLUDE_DIR)
MANDATORY_INCLUDE = $(addprefix -I, $(MANDATORY_INCLUDE_DIRS))
# mandatory libraries
MANDATORY_ARC_NAMES = $(COMMON_ARC_NAMES) $(MANDATORY_ADDITIONAL_ARC_NAMES)
MANDATORY_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(MANDATORY_ARC_NAMES))
MANDATORY_ARCS = $(foreach d,$(MANDATORY_ARC_NAMES),$(ARC_DIR)/$(d)/$(d:ft_%=libft%).a) $(COMMON_EXTERNAL_ARCS)

# bonus objs
BONUS_OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(COMMON_OBJ_DIRS) $(BONUS_ADDITIONAL_OBJ_DIRS))
BONUS_SRCS = $(COMMON_SRCS) $(BONUS_ADDITIONAL_SRCS)
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))
# bonus includes
BONUS_INCLUDE_DIRS = $(COMMON_INCLUDE_DIRS) $(BONUS_ADDITIONAL_INCLUDE_DIR)
BONUS_INCLUDE = $(addprefix -I, $(BONUS_INCLUDE_DIRS))
# bonus libraries
BONUS_ARC_NAMES = $(COMMON_ARC_NAMES) $(BONUS_ADDITIONAL_ARC_NAMES)
BONUS_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(BONUS_ARC_NAMES))
BONUS_ARCS = $(foreach d,$(BONUS_ARC_NAMES),$(ARC_DIR)/$(d)/$(d:ft_%=libft%).a) $(COMMON_EXTERNAL_ARCS)

# bonus and mandatory arcs (for cleaning)
ALL_ARC_NAMES = $(COMMON_ARC_NAMES) $(MANDATORY_ADDITIONAL_ARC_NAMES) $(BONUS_ADDITIONAL_ARC_NAMES)
ALL_ARC_DIRS = $(addprefix $(ARC_DIR)/, $(ALL_ARC_NAMES))

ifndef __BONUS__
RUNTIME_NAME = $(NAME)
RUNTIME_OBJS = $(MANDATORY_OBJS)
RUNTIME_OBJ_DIRS = $(MANDATORY_OBJ_DIRS)
RUNTIME_ARCS = $(MANDATORY_ARCS)
RUNTIME_INCLUDE = $(MANDATORY_INCLUDE)
else
RUNTIME_NAME = $(BONUS_NAME)
RUNTIME_OBJS = $(BONUS_OBJS)
RUNTIME_OBJ_DIRS = $(BONUS_OBJ_DIRS)
RUNTIME_ARCS = $(BONUS_ARCS)
RUNTIME_INCLUDE = $(BONUS_INCLUDE)
endif

all: $(RUNTIME_NAME)

bonus:
	make all __BONUS__=1

$(ARC_DIR)/%.a:
	make -C $(dir $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(RUNTIME_INCLUDE) 

$(RUNTIME_OBJS): | $(RUNTIME_OBJ_DIRS)

$(RUNTIME_OBJ_DIRS):
	$(foreach dir, $@, mkdir -p $(dir);)

$(RUNTIME_NAME): $(RUNTIME_ARCS) $(RUNTIME_OBJS)
	$(CC) $(LEAKS) $(DEBUG) $(CFLAGS) $(LIBS) $(RUNTIME_OBJS) $(RUNTIME_ARCS) -o $(RUNTIME_NAME)

clean:
	$(foreach d, $(ALL_ARC_DIRS), make -C $(d) fclean;)
	rm -rf $(LIBMLX)/build
	rm -rf $(OBJ_DIR)


fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

# External_ARCS
$(COMMON_EXTERNAL_ARCS):
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

re: fclean all

.PHONY: re clean fclean all bonus
