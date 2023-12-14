cc = c++
cflags = -Wall -Wextra -Werror -std=c++98
NAME = fixed
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(cc) $(cflags) -c $^ -o $@

$(NAME): $(OBJS)
	$(cc) $(cflags) $^ -o $@


.PHONY: clean
clean:
	rm -f $(OBJS)


.PHONY: fclean
fclean: clean
	rm -f $(NAME)


.PHONY: re
re: fclean
	make all
