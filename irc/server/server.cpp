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

using namespace std;

// class User {
//     public:
//     enum eRole
//     {
//         op = 0,
//         normal = 1
//     };
//     private:
//     std::string mUsername;
//     std::string mNickname;
//     std::string mPassword;
//     eRole       mRole;
//     public:
// };

class ServerSocket
{
private:
    int mSocket;
    ServerSocket(){};

public:
    class SocketInitException : public std::exception
    {
    public:
        virtual char *what() const throw()
        {
            return "Failed to open socket";
        }
    };
    class BindFailedException : public std::exception
    {
    public:
        virtual char *what() const throw()
        {
            return "Failed to bind";
        }
    };
    class ListenFailedException : public std::exception
    {
    public:
        virtual char *what() const throw()
        {
            return "Failed to listen";
        }
    };
    ServerSocket(int port) : mSocket(socket(PF_INET, SOCK_STREAM, 0))
    {
        if (mSocket == -1)
            throw SocketInitException();

        sockaddr_in mServerAddr;
        memset(&mServerAddr, 0, sizeof(mServerAddr));
        mServerAddr.sin_family = AF_INET;
        mServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        mServerAddr.sin_port = htons(port);
        if (bind(mSocket, (struct sockaddr *)&mServerAddr, sizeof(mServerAddr)) == -1)
            throw BindFailedException();
        // exit_with_perror("bind() error\n" + string(strerror(errno)));

        if (listen(mSocket, 5) == -1)
            throw ListenFailedException();
        // exit_with_perror("listen() error\n" + string(strerror(errno)));
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

class Event
{
};

class EventQueue
{
private:
    int mKq;
    std::vector<struct kevent> mChangeList;
    Event mapKeventToEvent(struct kevent &kevent)
    {
        return Event();
    }

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

    void addReadEvent(int target)
    {
        struct kevent new_event;
        EV_SET(&new_event, target, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
        mChangeList.push_back(new_event);
    }
    void addWriteEvent(int target)
    {
        struct kevent new_event;
        EV_SET(&new_event, target, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
        mChangeList.push_back(new_event);
    }
    std::vector<Event> getEvents(int size)
    {
        // return kevent(mKq, &mChangeList[0], mChangeList.size(), event_buf, size, NULL);
    }
};

// on('event', doSomething)
// -> doSomething에서 서버의 상태를 바꿔야한다면?

class IEventHandler
{
private:

public:
    virtual bool handler(IEvent &event) const = 0;
};

class Server
{
private:
    EventQueue mQ;
    ServerSocket sock;
    // EventTable eventHandlerTable
public:
    Server()
        : sock(3000)
    {
        mQ.addReadEvent(sock.getSocket());
    }
    void addEventListener(IEvent &event, IEventHandler &handler)
    {
        // eventHandlerTable[event].append(handler);
    }
    void run()
    {
        while (true)
        {
            struct kevent event_buffer[10];
            int eventCount = mQ.getEvents(event_buffer, 10);
            for (int i = 0; i < eventCount; ++i)
            {
                struct kevent &event = event_buffer[i];
                // handleEvent(event_buffer[i]);
            }
        }
    }
};

void exit_with_perror(const string &msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void change_events(vector<struct kevent> &change_list, uintptr_t ident, int16_t filter,
                   uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
{
    struct kevent temp_event;

    EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
    change_list.push_back(temp_event);
}

void disconnect_client(int client_fd, map<int, string> &clients)
{
    cout << "client disconnected: " << client_fd << endl;
    close(client_fd);
    clients.erase(client_fd);
}

int main()
{
    /* init server socket and listen */
    int server_socket;
    struct sockaddr_in server_addr;

    if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        exit_with_perror("socket() error\n" + string(strerror(errno)));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(3000);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        exit_with_perror("bind() error\n" + string(strerror(errno)));

    if (listen(server_socket, 5) == -1)
        exit_with_perror("listen() error\n" + string(strerror(errno)));
    // fcntl(server_socket, F_SETFL, O_NONBLOCK);

    /* init kqueue */
    int kq;
    if ((kq = kqueue()) == -1)
        exit_with_perror("kqueue() error\n" + string(strerror(errno)));

    map<int, string> clients;          // map for client socket:data
    vector<struct kevent> change_list; // kevent vector for changelist
    struct kevent event_list[8];       // kevent array for eventlist

    /* add event for server socket */
    change_events(change_list, server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    cout << "echo server started" << endl;

    /* main loop */
    int new_events;
    struct kevent *curr_event;
    while (1)
    {
        std::cout << "[fetching events]" << std::endl;
        /*  apply changes and return new events(pending events) */
        new_events = kevent(kq, &change_list[0], change_list.size(), event_list, 8, NULL);
        if (new_events == -1)
            exit_with_perror("kevent() error\n" + string(strerror(errno)));

        change_list.clear(); // clear change_list for new changes

        std::cout << "[loop]" << std::endl;
        for (int i = 0; i < new_events; ++i)
        {
            curr_event = &event_list[i];
            std::cout << "event info : " << curr_event->ident << " filter : " << curr_event->filter << " flags : " << curr_event->flags << " fflags : " << curr_event->fflags << std::endl;

            /* check error event return */
            if (curr_event->flags & EV_ERROR)
            {
                if (curr_event->ident == (uintptr_t)server_socket)
                    exit_with_perror("server socket error");
                else
                {
                    cerr << "client socket error" << endl;
                    disconnect_client(curr_event->ident, clients);
                }
            }
            else if (curr_event->filter == EVFILT_READ)
            {
                if (curr_event->ident == (uintptr_t)server_socket)
                {
                    /* accept new client */
                    int client_socket;
                    cout << "try listen" << endl;
                    if ((client_socket = accept(server_socket, NULL, NULL)) == -1)
                        exit_with_perror("accept() error\n" + string(strerror(errno)));
                    cout << "accept new client: " << client_socket << endl;
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);

                    /* add event for client socket - add read && write event */
                    change_events(change_list, client_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
                    change_events(change_list, client_socket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
                    // change_events(change_list, client_socket, EVFILT_READ, EV_DISABLE, 0, 0, NULL);
                    clients[client_socket] = "server: ";
                }
                else if (clients.find(curr_event->ident) != clients.end())
                {
                    /* read data from client */
                    char buf[1024];
                    int n = read(curr_event->ident, buf, sizeof(buf));

                    if (n <= 0)
                    {
                        if (n < 0)
                            cerr << "client read error!" << endl;
                        disconnect_client(curr_event->ident, clients);
                    }
                    else
                    {
                        buf[n] = '\0';
                        clients[curr_event->ident] += buf;
                        cout << "received data from " << curr_event->ident << ": " << clients[curr_event->ident] << endl;
                    }
                }
            }
            else if (curr_event->filter == EVFILT_WRITE)
            {
                /* send data to client */
                map<int, string>::iterator it = clients.find(curr_event->ident);
                if (it != clients.end())
                {
                    if (clients[curr_event->ident] != "")
                    {
                        int n;
                        if ((n = write(curr_event->ident, clients[curr_event->ident].c_str(),
                                       clients[curr_event->ident].size()) == -1))
                        {
                            cerr << "client write error!" << endl;
                            disconnect_client(curr_event->ident, clients);
                        }
                        else
                        {
                            clients[curr_event->ident].clear();
                            // disconnect_client(curr_event->ident, clients);
                        }
                    }
                }
            }
        }
    }
    return (0);
}