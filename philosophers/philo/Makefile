CC		= cc
CFLAGS	= -g -fsanitize=address -Wall -Wextra -Werror

#settings==========================

NAME	= philo

SRCS	=	main.c parse_args.c \
			utils/ft_atoi.c utils/ft_split.c utils/ft_strlen.c
OBJS	= $(SRCS:.c=.o)

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
