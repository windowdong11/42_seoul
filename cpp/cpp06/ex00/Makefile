cc = c++
# DEBUG=-g
OPTIONS = -Wall -Wextra -Werror -std=c++98 $(CPPFLAGS) $(DEBUG)
NAME = form
SRCS = AForm.cpp Bureaucrat.cpp Intern.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(cc) $(OPTIONS) -c $^ -o $@

$(NAME): $(OBJS)
	$(cc) $(OPTIONS) $^ -o $@


.PHONY: clean
clean:
	rm -f $(OBJS)


.PHONY: fclean
fclean: clean
	rm -f $(NAME)


.PHONY: re
re: fclean
	make all
