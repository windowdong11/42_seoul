#include <sys/types.h>
// #include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <map>
#include <vector>

#include "Socket.hpp"
#include "EventQueue.hpp"
#include "User.hpp"
#include "Channel.hpp"

using namespace std;

class UserRepository
{
public:
    UserRepository(){};
    ~UserRepository(){};
    void addUser(User user)
    {
        mUserList.push_back(user);
    }
    bool removeUserBySocket(int socket)
    {
        for (std::vector<User>::iterator it = mUserList.begin(); it != mUserList.end(); ++it)
        {
            if (it->getSocket().getSocketFd() == socket)
            {
                mUserList.erase(it);
                return true;
            }
        }
        return false;
    }
    std::vector<User>& getUserList()
    {
        return mUserList;
    }
private:
    std::vector<User> mUserList;
};

class ChannelRepository
{
public:
    ChannelRepository(){};
    ~ChannelRepository(){};
    void addChannel(Channel channel)
    {
        mChannelList.push_back(channel);
    }
    bool removeChannelBySocket(int socket)
    {
        for (std::vector<Channel>::iterator it = mChannelList.begin(); it != mChannelList.end(); ++it)
        {
            if (it->getSocket().getSocketFd() == socket)
            {
                mChannelList.erase(it);
                return true;
            }
        }
        return false;
    }
    std::vector<Channel>& getChannelList()
    {
        return mChannelList;
    }
private:
    std::vector<Channel> mChannelList;
};

int main()
{
    /* init server socket and listen */
    Socket server_socket(socket(PF_INET, SOCK_STREAM, 0));

    if (server_socket.bind(3000) == -1)
    {
        cerr << "bind error!" << endl;
        return (1);
    }

    if (server_socket.listen(10) == -1)
    {
        cerr << "listen error!" << endl;
        return (1);
    }
    // fcntl(server_socket, F_SETFL, O_NONBLOCK);

    /* init kqueue */
    EventQueue kq;
    std::map<int, string> clients;      // map for client socket:data
    // std::vector<User> userRepository; // vector for client socket
    // std::vector<User> userRepository;    // vector for user repository
    UserRepository userRepository;

    /* add event for server socket */
    kq.addReadEvent(server_socket.getSocketFd());

    /* main loop */
    while (1)
    {
        std::cout << "[fetching events]" << std::endl;
        int eventCnt;
        struct kevent eventList[8];
        eventCnt = kq.getEvents(eventList, 8);

        std::cout << eventCnt << " events fetched" << std::endl;
        for (int i = 0; i < eventCnt; ++i)
        {
            struct kevent &curr_event = eventList[i];

            /* check error event return */
            if (curr_event.flags & EV_ERROR)
            {
                if (curr_event.ident == (uintptr_t)server_socket.getSocketFd())
                {
                    cerr << "server socket error" << endl;
                    return (1);
                }
                else
                {
                    cerr << "client socket error" << endl;
                }
            }
            else if (curr_event.filter == EVFILT_READ)
            {
                // check if ev_eof is set
                if (curr_event.flags & EV_EOF)
                {
                    std::cout << "EOF" << std::endl;
                    if (userRepository.removeUserBySocket(curr_event.ident))
                    {
                        std::cout << "erase" << std::endl;
                        clients.erase(curr_event.ident);
                    }
                    else
                    {
                        std::cout << "socket not found" << std::endl;
                        return (1);
                    }
                }
                std::cout << "read event : " << curr_event.ident << std::endl;
                if (curr_event.ident == (uintptr_t)server_socket.getSocketFd())
                {
                    std::cout << "server" << std::endl;
                    /* accept new client */
                    int client_socket;

                    if ((client_socket = server_socket.accept()) == -1)
                    {
                        cerr << "accept error!" << endl;
                        return (1);
                    }
                    std::cout << "accept new client: " << client_socket << std::endl;
                    userRepository.addUser(User(client_socket));
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);

                    /* add event for client socket - add read && write event */
                    kq.addReadEvent(client_socket);
                    clients[client_socket] = "server: ";
                }
                else if (clients.find(curr_event.ident) != clients.end())
                {
                    std::cout << "client" << std::endl;
                    /* read data from client */
                    char buf[1024];
                    int n = read(curr_event.ident, buf, sizeof(buf));

                    if (n <= 0)
                    {
                        if (n < 0)
                            cerr << "client read error!" << endl;
                        userRepository.removeUserBySocket(curr_event.ident);
                    }
                    else
                    {
                        buf[n] = '\0';
                        if (std::string("end") == buf)
                        {
                            std::cout << "end!!" << std::endl;

                            if (userRepository.removeUserBySocket(curr_event.ident))
                            {
                                std::cout << "erase" << std::endl;
                            }
                            else
                            {
                                std::cout << "socket not found" << std::endl;
                                return (1);
                            }
                            clients.erase(curr_event.ident);
                        }
                        else if (std::string("send") == buf)
                        {
                            kq.addWriteEvent(curr_event.ident);
                        }
                        else
                        {
                            clients[curr_event.ident] += buf;
                        }
                        cout << "received data from " << curr_event.ident << ": " << clients[curr_event.ident] << endl;
                    }
                }
            }
            else if (curr_event.filter == EVFILT_WRITE)
            {
                /* send data to client */
                map<int, string>::iterator it = clients.find(curr_event.ident);
                if (it != clients.end())
                {
                    int n;
                    if ((n = write(curr_event.ident, clients[curr_event.ident].c_str(), clients[curr_event.ident].length() + 1) == -1))
                    {
                        cerr << "client write error!" << endl;
                        userRepository.removeUserBySocket(curr_event.ident);
                    }
                    else
                    {
                        clients[curr_event.ident].erase(n);
                        if (clients[curr_event.ident].empty())
                        {
                            kq.removeWriteEvent(curr_event.ident);
                        }
                    }
                }
            }
        }
        std::cout << "> user list : " << userRepository.getUserList().size() << std::endl;
        for (std::vector<User>::iterator it = userRepository.getUserList().begin(); it != userRepository.getUserList().end(); ++it)
        {
            std::cout << "user : " << it->getSocket().getSocketFd() << std::endl;
        }
        std::cout << std::endl;
    }
    return (0);
}