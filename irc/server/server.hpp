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

class ServerSocket
{
private:
    int mSocket;
    ServerSocket(){};

public:
    ServerSocket(int port) : mSocket(socket(PF_INET, SOCK_STREAM, 0))
    {
        if (mSocket == -1)
            throw std::runtime_error("Failed to open socket");

        sockaddr_in mServerAddr;
        memset(&mServerAddr, 0, sizeof(mServerAddr));
        mServerAddr.sin_family = AF_INET;
        mServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        mServerAddr.sin_port = htons(port);
        if (bind(mSocket, (struct sockaddr *)&mServerAddr, sizeof(mServerAddr)) == -1)
						throw std::runtime_error("Failed to bind");

        if (listen(mSocket, 5) == -1)
						throw std::runtime_error("Failed to listen");
    }
    ~ServerSocket()
    {
        close(mSocket);
    }
    int getSocket() const
    {
        return mSocket;
    }
};

struct Event
{
	// some data
};

enum EventType
{
		READ,
		WRITE,
		// ...
};

class EventQueue
{
private:
    int mKq;
    std::vector<struct kevent> mChangeList;
    Event mapKeventToEvent(struct kevent &kevent);

public:
    class InitFailedException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Failed to initialize.";
        }
    };
    EventQueue()
        : mKq(kqueue())
    {
        if (mKq == -1)
            throw InitFailedException();
    }

    void addReadTarget(int target);
    void addWriteTarget(int target);
    std::vector<Event> getEvents(int size);
		void handleEvents(int size);
		void addEventListener(/*...*/);
};

// on('event', doSomething)
// -> doSomething에서 서버의 상태를 바꿔야한다면?

class IEventHandler
{
public:
    virtual bool handler(Event &ev) const = 0;
};

class Server
{
private:
    EventQueue mQ;
    ServerSocket sock;
    std::map<EventType, std::vector<IEventHandler>> eventHandlerTable;
public:
    Server()
        : sock(3000)
    {
        mQ.addReadTarget(sock.getSocket());
    }
    void addEventListener(EventType type, IEventHandler &handler);
    void run();
};