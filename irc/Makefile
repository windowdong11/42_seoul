cc = c++
# DEBUG=-g
cflags = -Wall -Wextra -Werror -std=c++98 $(CPPFLAGS) $(DEBUG) -I./include
NAME = ft_irc
SRCS = src/Command/Command.cpp src/Command/INVITE/INVITE.cpp src/Command/JOIN/JOIN.cpp src/Command/KICK/KICK.cpp src/Command/MODE/MODE.cpp src/Command/NICK/NICK.cpp src/Command/PART/PART.cpp src/Command/PASS/PASS.cpp src/Command/PING/PING.cpp src/Command/PRIVMSG/PRIVMSG.cpp src/Command/QUIT/QUIT.cpp src/Command/TOPIC/TOPIC.cpp src/Command/USER/USER.cpp src/channel/Channel.cpp src/event/EventQueue.cpp src/event/Subject.cpp src/main.cpp src/server/server.cpp src/socket/Socket.cpp src/user/User.cpp
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
