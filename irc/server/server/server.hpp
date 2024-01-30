#ifndef SERVER_HPP
#define SERVER_HPP

/* include headers */

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <map>
#include <vector>
#include "../channel/Channel.hpp"
#include "../event/EventQueue.hpp"
#include "../user/User.hpp"
#include "../socket/Socket.hpp"

using namespace std;

// class ServerSocket
// {
// private:
// 	uintptr_t mSocket;
// 	ServerSocket(){};

// public:
// 	class SocketInitException : public std::exception
// 	{
// 	public:
// 		virtual char *what() const throw()
// 		{
// 			return "Failed to open socket";
// 		}
// 	};
// 	class BindFailedException : public std::exception
// 	{
// 	public:
// 		virtual char *what() const throw()
// 		{
// 			return "Failed to bind";
// 		}
// 	};
// 	class ListenFailedException : public std::exception
// 	{
// 	public:
// 		virtual char *what() const throw()
// 		{
// 			return "Failed to listen";
// 		}
// 	};
// 	ServerSocket(int port) : mSocket(socket(PF_INET, SOCK_STREAM, 0))
// 	{
// 		if (mSocket == -1)
// 			throw SocketInitException();

// 		sockaddr_in mServerAddr;
// 		memset(&mServerAddr, 0, sizeof(mServerAddr));
// 		mServerAddr.sin_family = AF_INET;
// 		mServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
// 		mServerAddr.sin_port = htons(port);
// 		if (bind(mSocket, (struct sockaddr *)&mServerAddr, sizeof(mServerAddr)) == -1)
// 			throw BindFailedException();
// 		// exit_with_perror("bind() error\n" + string(strerror(errno)));

// 		if (listen(mSocket, 5) == -1)
// 			throw ListenFailedException();
// 		// exit_with_perror("listen() error\n" + string(strerror(errno)));
// 	}
// 	~ServerSocket()
// 	{
// 		close(mSocket);
// 	}
// 	uintptr_t getSocket() const
// 	{
// 		return mSocket;
// 	}
// };

// class EventQueue
// {
// private:
// 	int mKq;
// 	std::vector<struct kevent> mChangeList;

// public:
// 	class InitFailedException : public std::exception
// 	{
// 	public:
// 		virtual const char *what() const throw()
// 		{
// 			return "Failed to initialize.";
// 		}
// 	};
// 	EventQueue()
// 			: mKq(kqueue())
// 	{
// 		if (mKq == -1)
// 			throw InitFailedException();
// 	}

// 	void addReadEvent(int target)
// 	{
// 		struct kevent new_event;
// 		EV_SET(&new_event, target, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
// 		mChangeList.push_back(new_event);
// 	}
// 	void addWriteEvent(int target)
// 	{
// 		struct kevent new_event;
// 		EV_SET(&new_event, target, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
// 		mChangeList.push_back(new_event);
// 	}
// 	int getEvents(struct kevent *event_buf, int size)
// 	{
// 		return kevent(mKq, &mChangeList[0], mChangeList.size(), event_buf, size, NULL);
// 	}
// };

// on('event', doSomething)
// -> doSomething에서 서버의 상태를 바꿔야한다면?

// class Channel
// {
// 	private:
// 		std::string mChannelName;
// 		User &mOperator;
// };

// class Client
// {

// 	public:
// 	Client();
// };

class EventQueue
{
public:
  EventQueue();
  void addReadEvent(int target_fd);
  void addWriteEvent(int target_fd);
  void removeReadEvent(int target_fd);
  void removeWriteEvent(int target_fd);

  int getEvents(struct kevent *event_buf, int size);
private:
  int mKq;
  std::vector<struct kevent> mChangeList;
};

void EventQueue::addReadEvent(int target_fd)
{
	struct kevent new_event;
	EV_SET(&new_event, target_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	mChangeList.push_back(new_event);
}

void EventQueue::addWriteEvent(int target_fd)
{
	struct kevent new_event;
	EV_SET(&new_event, target_fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	mChangeList.push_back(new_event);
}

void EventQueue::removeReadEvent(int target_fd)
{
	struct kevent new_event;
	EV_SET(&new_event, target_fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
	mChangeList.push_back(new_event);
}

void EventQueue::removeWriteEvent(int target_fd)
{
	struct kevent new_event;
	EV_SET(&new_event, target_fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
	mChangeList.push_back(new_event);
}

int EventQueue::getEvents(struct kevent *event_buf, int size)
{
	return kevent(mKq, &mChangeList[0], mChangeList.size(), event_buf, size, NULL);
}

/** Event Queue End */

class IRC_COMMAND
{
public:
	enum EventType
	{
		IRC_CMD_CONNECT,
		IRC_CMD_JOIN,
	};
};

class EventMsg
{
};

// class IEventHandler
// {
// public:
// 	virtual bool handler(EventMsg &event) const = 0;
// };

// typedef for event handler
typedef bool (*IEventHandler)(EventMsg &event);

class Client
{
};

class Server
{
private:
	EventQueue mEventQueue;
	Socket mSock;
	std::map<IRC_COMMAND::EventType, std::vector<IEventHandler>> mEventHandlerMap;
	// Ch(n) - User(1) - Sock(1)

public:
	Server();
	void addEventListener(IRC_COMMAND::EventType type, IEventHandler &handler);
	void run();
};


void Server::addEventListener(IRC_COMMAND::EventType type, IEventHandler &handler)
{
	mEventHandlerMap[type].push_back(handler);
}

Server::Server()
		: mSock(3000)
{
	mEventQueue.addReadEvent(mSock.getSocketFd());
}

void Server::run()
{
	while (true)
	{
		struct kevent event_buffer[10];
		int eventCount = mEventQueue.getEvents(event_buffer, 10);
		for (int i = 0; i < eventCount; ++i)
		{
			if (event_buffer[i].filter == EVFILT_READ)
			{
				if (event_buffer[i].ident == mSock.getSocketFd())
				{
					int client_sock = accept(mSock.getSocketFd(), NULL, NULL);
					if (client_sock == -1)
						throw std::runtime_error("failed to accept socket");

					fcntl(client_sock, F_SETFL, O_NONBLOCK);
					mEventQueue.addReadEvent(client_sock);
					// clients[client_sock] = Client(client_sock);
				}
				else
				{
					std::vector<IEventHandler> &handlers = mEventHandlerMap[IRC_COMMAND::EventType::IRC_CMD_CONNECT];
					for (std::vector<IEventHandler>::iterator it = handlers.begin(); it != handlers.end(); ++it)
					{
						IRC_COMMAND some_event;
						(*it).handler(some_event);
					}
				}
			}
		}
	}
}

#endif
