#include <sys/types.h>
// #include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include 

#include <iostream>
#include <map>
#include <vector>

#include "server/socket/Socket.hpp"
#include "server/event/EventQueue.hpp"

int main()
{
    /* init server socket and listen */
    Socket server_socket(socket(PF_INET, SOCK_STREAM, 0));
    struct sockaddr_in server_addr;

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
    std::vector<Socket> client_sockets; // vector for client socket

    /* add event for server socket */
    kq.addReadEvent(server_socket.getSocketFd());

    /* main loop */
    while (1)
    {
        std::cout << "[fetching events]" << std::endl;
        int eventCnt;
        struct kevent eventList[8];
        eventCnt = kq.getEvents(eventList, 8);
        if (eventCnt == -1)
        {
            cerr << "kevent error!" << endl;
            return (1);
        }

        for (int i = 0; i < eventCnt; ++i)
        {
            struct kevent &curr_event = eventList[i];

            /* check error event return */
            if (curr_event.flags & EV_ERROR)
            {
                if (curr_event.ident == (uintptr_t)server_socket)
                    else
                    {
                        cerr << "client socket error" << endl;
                        disconnect_client(curr_event.ident, clients);
                    }
            }
            else if (curr_event.filter == EVFILT_READ)
            {
                if (curr_event.ident == (uintptr_t)server_socket)
                {
                    /* accept new client */
                    int client_socket;

                    if ((client_socket = server_socket.accept()) == -1)
                    {
                        client_sockets.push_back(Socket(client_socket));
                        fcntl(client_socket, F_SETFL, O_NONBLOCK);
                    }

                    /* add event for client socket - add read && write event */
                    kq.addReadEvent(client_socket);
                    clients[client_socket] = "server: ";
                }
                else if (clients.find(curr_event.ident) != clients.end())
                {
                    /* read data from client */
                    char buf[1024];
                    int n = read(curr_event.ident, buf, sizeof(buf));

                    if (n <= 0)
                    {
                        if (n < 0)
                            cerr << "client read error!" << endl;
                        std::vector::iterator it = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                        if (it != client_sockets.end())
                            client_sockets.erase(it);
                    }
                    else
                    {
                        buf[n] = '\0';
                        clients[curr_event.ident] += buf;
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
                    if (clients[curr_event.ident] != "")
                    {
                        int n;
                        if ((n = write(curr_event.ident, clients[curr_event.ident].c_str(), clients[curr_event.ident].size()) == -1))
                        {
                            cerr << "client write error!" << endl;
                            std::vector::iterator it = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                            if (it != client_sockets.end())
                                client_sockets.erase(it);
                        }
                        else
                        {
                            clients[curr_event.ident].clear();
                            // disconnect_client(curr_event->ident, clients);
                        }
                    }
                }
            }
        }
    }
    return (0);
}