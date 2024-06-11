cc = c++
OPTIONS = -Wall -Wextra -Werror -std=c++98 -MMD -MP $(CPPFLAGS)
NAME = RPN
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(cc) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJS)
	$(cc) $(OPTIONS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

-include $(DEPS)
