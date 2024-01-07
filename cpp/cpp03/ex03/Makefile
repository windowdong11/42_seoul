cc = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = claptrap
SRCS = ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(cc) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(cc) $(CFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -f $(OBJS)


.PHONY: fclean
fclean: clean
	rm -f $(NAME)


.PHONY: re
re: fclean
	make all
