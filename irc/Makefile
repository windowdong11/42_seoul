cc = c++
# DEBUG=-g
cflags = -Wall -Wextra -Werror -std=c++98 $(CPPFLAGS) $(DEBUG)
NAME = ft_irc
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, channel/Channel.cpp event/EventQueue.cpp main.cpp socket/Socket.cpp user/User.cpp)
OBJS = $(SRCS:.cpp=.o)
INCLUDES = -Iinclude

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(cc) $(cflags) -c $^ $(INCLUDES) -o $@

$(NAME): $(OBJS)
	$(cc) $(cflags) $^ $(INCLUDES) -o $@


.PHONY: clean
clean:
	rm -f $(OBJS)


.PHONY: fclean
fclean: clean
	rm -f $(NAME)


.PHONY: re
re: fclean
	make all
