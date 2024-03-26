cc = c++
OPTIONS = -Wall -Wextra -Werror -std=c++98 -MMD -MP $(CPPFLAGS)
NAME = template_function
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

-include $(DEPS)

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

.PHONY: cre
cre:
	@$(MAKE) re CPPFLAGS="-D TEST_CONST_SWAP=1"