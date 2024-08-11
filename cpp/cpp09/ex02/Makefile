cc = c++
OPTIONS = -Wall -Wextra -Werror -std=c++98 -MMD -MP $(CPPFLAGS)
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
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

.PHONY: test
test:
	shuf -i 1-6000 > test.in
	./$(NAME) $$(cat test.in) | tr ' ' '\n' > test.out
	cat test.out | tr ' ' '\n' | sort -g > test.in.sorted
	diff test.in.sorted test.out && echo "OK" || echo "KO"

.PHONY: cleantest
cleantest:
	rm -f test.in test.out test.in.sorted

.PHONY: cleanall
cleanall: cleantest fclean

-include $(DEPS)
