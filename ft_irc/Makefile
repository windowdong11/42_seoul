#parameters====================================================================

CXX			= c++

COMMONFLAGS	=
CXXFLAGS	= $(COMMONFLAGS) -Wall -Wextra -Werror -std=c++98 -O2 $(LOG_ON_FLAG)
LDFLAGS		= $(COMMONFLAGS)

NAME	= ircserv
INCLUDE	= includes/

#sources=======================================================================

SRCS	= srcs/main.cpp \
		  srcs/ChannelDB/Channel.cpp \
		  srcs/ChannelDB/ChannelDB.cpp \
		  srcs/Command/Command.cpp \
		  srcs/Command/INVITE/INVITE.cpp \
		  srcs/Command/JOIN/JOIN.cpp \
		  srcs/Command/KICK/KICK.cpp \
		  srcs/Command/MODE/MODE.cpp \
		  srcs/Command/NICK/NICK.cpp \
		  srcs/Command/PART/PART.cpp \
		  srcs/Command/PASS/PASS.cpp \
		  srcs/Command/PING/PING.cpp \
		  srcs/Command/PRIVMSG/PRIVMSG.cpp \
		  srcs/Command/QUIT/QUIT.cpp \
		  srcs/Command/TOPIC/TOPIC.cpp \
		  srcs/Command/USER/USER.cpp \
		  srcs/Command/CAP/CAP.cpp \
		  srcs/IndexManager/IndexManager.cpp \
		  srcs/Server/FileContainer.cpp \
		  srcs/Server/FixedBufferArray.cpp \
		  srcs/Server/Message/Message.cpp \
		  srcs/Server/Server.cpp \
		  srcs/UserDB/User.cpp \
		  srcs/UserDB/UserDB.cpp

OBJS	= $(SRCS:.cpp=.o)

TARGET_OBJS = $(OBJS)

ifdef LOG_ON
	LOG_ON_FLAG = -DLOG_ON
else
endif

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CXX) -o $@ $(TARGET_OBJS) $(LDFLAGS)

.PHONY: logon
logon :
	make $(NAME) LOG_ON=0

#const options=================================================================

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all

.PHONY: lre
lre :
	make fclean
	make logon
