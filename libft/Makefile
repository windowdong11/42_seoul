CC = cc
CFLAGS = -Wall -Wextra -Werror -c

SRCDIR = $(CURDIR)

NAME = libft.a
SOURCES = $(SRCDIR)/$(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME) clean

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(CURDIR)

$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean