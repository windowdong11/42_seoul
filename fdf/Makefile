
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

BASE_SRC = mlx_utils/init.c mlx_utils/render.c \
utils/colors.c
SRCS = $(BASE_SRC) main.c
OBJS = $(SRCS:.c=.o)

ARC_DEPS = libft
ARC_DIRS = $(addprefix include/, $(ARC_DEPS))
ARCS = $(addprefix include/, $(foreach d, $(ARC_DEPS), $(d)/$(d:ft_%=libft%).a))

LIBMLX	= ./MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= -L./include -lmlx42 -ldl -lglfw -pthread -lm -L$(LIBMLX)/build -L/Users/dowon/.brew/lib/


all: arcs libmlx $(NAME)

bonus: arcs libmlx $(BONUS_NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

arcs:
	$(foreach d, $(ARC_DIRS), make -C $(d);)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $^ -o $@

$(BONUS_NAME): $(BONUS_OBJS) $(ARCS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(ARCS) $(HEADERS) -o $(BONUS_NAME)

$(NAME): $(OBJS) $(ARCS)
	$(CC) $(CFLAGS) $(LIBS) $(ARCS) $(OBJS) $(HEADERS) -o $(NAME)


clean:
	$(foreach d, $(ARC_DIRS), make -C $(d) fclean;)
	rm -rf $(LIBMLX)/build
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re clean fclean all bonus arcs libmlx