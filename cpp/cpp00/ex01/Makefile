# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dowon <dowon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 20:56:09 by dowon             #+#    #+#              #
#    Updated: 2023/10/24 21:05:15 by dowon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = c++
cflags = -Wall -Wextra -Werror -std=c++98
NAME = myphonebook
SRCS = main.cpp Contact.cpp PhoneBook.cpp
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
