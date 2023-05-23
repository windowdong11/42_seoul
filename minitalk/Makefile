CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

SRC_COMMON = common.c

SRC_SERVER_DIR = mt_server/
FILES_SERVER = server.c
SRC_SERVER = $(SRC_COMMON) $(addprefix $(SRC_SERVER_DIR), $(FILES_SERVER))
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT_DIR = mt_client/
FILES_CLIENT = client.c
SRC_CLIENT = $(SRC_COMMON) $(addprefix $(SRC_CLIENT_DIR), $(FILES_CLIENT))
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

ARC_DIRS = ft_printf libft
ARCS = $(foreach d,$(ARC_DIRS),$(d)/$(d:ft_%=libft%).a)

bonus: all

all:
	$(foreach d, $(ARC_DIRS), make -C $(d);)
	$(foreach d, $(NAME), make $(d);)

%.o: %.c
	echo $@
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):
	make $(NAME_SERVER)
	make $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(ARCS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(ARCS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(ARCS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(ARCS) -o $(NAME_CLIENT)

clean:
	$(foreach d, $(ARC_DIRS), make -C $(d) fclean;)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus