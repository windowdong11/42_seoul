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
NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

.PHONY: all

%.cpp: %.o
	$(cc) $(cflags) -c $^ -o $@

$(NAME): $(OBJS)
	$(cc) $(cflags) $^ -o $@

clean:
	rm -f $(OBJS)

.PHONY: clean

fclean: clean
	rm -f $(NAME)

.PHONY: fclean

re: fclean
	make all

.PHONY: re
