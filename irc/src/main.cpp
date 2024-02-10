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
#include <sstream>

#include "Socket.hpp"
#include "EventQueue.hpp"
<<<<<<< Updated upstream
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
=======
#include "Hooks.hpp"
#include "User.hpp"
#include "Channel.hpp"

class Message
{
	public:
		Message(void);
		Message(const Message& source);
		Message&	operator=(const Message& source);
		~Message(void);

		int								GetUserId(void) const;
		std::string&					GetPrefix(void);
		const std::string&				GetPrefix(void) const;
		std::string&					GetCommand(void);
		const std::string&				GetCommand(void) const;
		std::vector<std::string>&		GetParameters(void);
		const std::vector<std::string>&	GetParameters(void) const;
		std::string&					GetTrailing(void);
		const std::string&				GetTrailing(void) const;
		std::string&					GetMessage(void);
		const std::string&				GetMessage(void) const;
		std::string&					GetRawMessageData(void);
		const std::string&				GetRawMessageData(void) const;

		bool							ParseMessage(int clientFd, std::string& message);

	private:
		void	ClearData(void);

		int							mUserId;
		std::string					mPrefix;
		std::string					mCommand;
		std::vector<std::string>	mParameters;
		std::string					mTrailing;
		std::string					mMessage;
		std::string					mRawMessage;
};

#include <sstream>
#include "Message.hpp"

Message::Message(void) {}

Message::Message(const Message& source)
	: mPrefix(source.mPrefix)
	, mCommand(source.mPrefix)
	, mMessage(source.mMessage)
	, mRawMessage(source.mRawMessage) {}

Message&	Message::operator=(const Message& source)
{
	if (this != &source)
	{
		mPrefix = source.mPrefix;
		mCommand = source.mCommand;
		mMessage = source.mMessage;
		mRawMessage = source.mRawMessage;
	}

	return (*this);
}

Message::~Message(void) {}

int								Message::GetUserId(void) const			{ return (mUserId); }
std::string&					Message::GetPrefix(void)				{ return (mPrefix); }
const std::string&				Message::GetPrefix(void) const			{ return (mPrefix); }
std::string&					Message::GetCommand(void)				{ return (mCommand); }
const std::string&				Message::GetCommand(void) const			{ return (mCommand); }
std::vector<std::string>&		Message::GetParameters(void)			{ return (mParameters); }
const std::vector<std::string>&	Message::GetParameters(void) const		{ return (mParameters); }
std::string&					Message::GetTrailing(void)				{ return (mTrailing); }
const std::string&				Message::GetTrailing(void) const		{ return (mTrailing); }
std::string&					Message::GetMessage(void)				{ return (mMessage); }
const std::string&				Message::GetMessage(void) const			{ return (mMessage); }
std::string&					Message::GetRawMessageData(void)		{ return (mRawMessage); }
const std::string&				Message::GetRawMessageData(void) const	{ return (mRawMessage); }

bool	Message::ParseMessage(int userId, std::string& message)
{
	std::istringstream	iss(message);
	std::string			token;

	mRawMessage = message;
	mUserId = userId;

	if (!message.empty() && message[0] == ':')
	{
		std::getline(iss, mPrefix, ' ');
		mPrefix = mPrefix.substr(1);
	}


	if (!std::getline(iss, mCommand, ' ')
	 || mCommand.empty() || mCommand[0] == ':')
	{
		ClearData();
		return (false);
	}

	std::getline(iss, mMessage);
	std::istringstream	iss2(mMessage);



	while (std::getline(iss2, token, ' '))
	{
		if (!token.empty())
		{
			if (token[0] == ':')
			{
				std::getline(iss2, mTrailing);
				mTrailing = token + " " + mTrailing;
				break;
			}
			else
			{
				mParameters.push_back(token);
			}
		}
	}

	return (true);
}

void	Message::ClearData(void)
{
	mPrefix.clear();
	mCommand.clear();
	mParameters.clear();
	mTrailing.clear();
	mMessage.clear();
	mRawMessage.clear();
}
>>>>>>> Stashed changes

int main()
{
    /* init server socket and listen */
    Socket server_socket(socket(PF_INET, SOCK_STREAM, 0));

    if (server_socket.bind(3000) == -1)
    {
        std::cout << "bind error!" << std::endl;
        return (1);
    }

    if (server_socket.listen(10) == -1)
    {
        std::cout << "listen error!" << std::endl;
        return (1);
    }
    // fcntl(server_socket, F_SETFL, O_NONBLOCK);

    /* init kqueue */
    EventQueue kq;
<<<<<<< Updated upstream
    std::map<int, string> clients;      // map for client socket:data
    // std::vector<User> userRepository; // vector for client socket
    // std::vector<User> userRepository;    // vector for user repository
    UserRepository userRepository;
=======
    std::map<int, std::string> read_buffer; // map for client socket:data
    std::map<int, std::string> write_buffer;
    std::vector<Socket> client_sockets;     // vector for client socket
    std::vector<User> users;
    std::vector<Channel> channels;
>>>>>>> Stashed changes

    /* add event for server socket */
    kq.addReadEvent(server_socket.getSocketFd());

    /* main loop */
    while (1)
    {
        std::cout << "[fetching events]" << std::endl;
        int eventCnt;
        struct kevent eventList[8];
        eventCnt = kq.getEvents(eventList, 8);
<<<<<<< Updated upstream
=======
        if (eventCnt == -1)
        {
            std::cout << "kevent error!" << std::endl;
            return (1);
        }
>>>>>>> Stashed changes

        std::cout << eventCnt << " events fetched" << std::endl;
        for (int i = 0; i < eventCnt; ++i)
        {
            struct kevent &curr_event = eventList[i];
            std::cout << "event info : " << curr_event.ident << " filter : " << curr_event.filter << " flags : " << curr_event.flags << " fflags : " << curr_event.fflags << std::endl;

            /* check error event return */
            if (curr_event.flags & EV_ERROR)
            {
                if (curr_event.ident == (uintptr_t)server_socket.getSocketFd())
                {
<<<<<<< Updated upstream
                    cerr << "server socket error" << endl;
=======
                    std::cout << "server socket error" << std::endl;
>>>>>>> Stashed changes
                    return (1);
                }
                else
                {
<<<<<<< Updated upstream
                    cerr << "client socket error" << endl;
=======
                    std::cout << "client socket error" << std::endl;
                    std::vector<Socket>::iterator cur_client = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                    if (cur_client != client_sockets.end())
                    {
                        cur_client->close();
                    }
                }
            }
            else if (curr_event.flags & EV_EOF)
            {
                std::cout << "client socket closed" << std::endl;
                std::vector<Socket>::iterator cur_client = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                if (cur_client != client_sockets.end())
                {
                    cur_client->close();
                    client_sockets.erase(cur_client);
>>>>>>> Stashed changes
                }
            }
            else if (curr_event.filter == EVFILT_READ)
            {
<<<<<<< Updated upstream
                // check if ev_eof is set
                if (curr_event.flags & EV_EOF)
=======
                if (curr_event.ident == (uintptr_t)server_socket.getSocketFd())
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
                        cerr << "accept error!" << endl;
                        return (1);
                    }
                    std::cout << "accept new client: " << client_socket << std::endl;
                    userRepository.addUser(User(client_socket));
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);

=======
                        std::cout << "accept error!" << std::endl;
                        return 1;
                    }
                    Socket newSocket(client_socket);
                    client_sockets.push_back(newSocket);
                    users.push_back(newSocket);
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);
>>>>>>> Stashed changes
                    /* add event for client socket - add read && write event */
                    kq.addReadEvent(client_socket);
                    std::cout << "accept new client: " << client_socket << std::endl;
                }
                else if (find(client_sockets.begin(), client_sockets.end(), curr_event.ident) != client_sockets.end())
                {
                    std::cout << "client" << std::endl;
                    /* read data from client */
                    char buf[1024];
                    int n = read(curr_event.ident, buf, sizeof(buf));

                    if (n <= 0)
                    {
                        if (n < 0)
<<<<<<< Updated upstream
                            cerr << "client read error!" << endl;
                        userRepository.removeUserBySocket(curr_event.ident);
=======
                            std::cout << "client read error!" << std::endl;
                        std::vector<Socket>::iterator cur_client = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                        if (cur_client != client_sockets.end())
                        {
                            cur_client->close();
                            client_sockets.erase(cur_client);
                        }
>>>>>>> Stashed changes
                    }
                    else
                    {
                        buf[n] = '\0';
<<<<<<< Updated upstream
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
=======
                        read_buffer[curr_event.ident] += buf;
                        std::cout << "received data from " << curr_event.ident << ": " << read_buffer[curr_event.ident] << std::endl;
                        // TODO : parse message
                        Message msg;
                        if (msg.ParseMessage(curr_event.ident, read_buffer[curr_event.ident]))
                            continue;
                        if (msg.GetCommand() == "QUIT")
                        {
                            HookFunctionQuit(msg);
                            std::vector<Socket>::iterator cur_client = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                            if (cur_client != client_sockets.end())
                            {
                                cur_client->close();
                                client_sockets.erase(cur_client);
                            }
                        }
                        else if (msg.GetCommand() == "PASS")
                            HookFunctionPass(msg);
                        else if (msg.GetCommand() == "USER")
                            HookFunctionUser(msg);
                        else if (msg.GetCommand() == "NICK")
                            HookFunctionNick(msg);
                        else if (msg.GetCommand() == "PRIVMSG")
                            HookFunctionPrivmsg(msg);
                        else if (msg.GetCommand() == "INVITE")
                            HookFunctionInvite(msg);
                        else if (msg.GetCommand() == "JOIN")
                            HookFunctionJoin(msg);
                        else if (msg.GetCommand() == "KICK")
                            HookFunctionKick(msg);
                        else if (msg.GetCommand() == "PART")
                            HookFunctionPart(msg);
                        else if (msg.GetCommand() == "PASS")
                            HookFunctionPass(msg);
                        else if (msg.GetCommand() == "PING")
                            HookFunctionPing(msg);
                        else if (msg.GetCommand() == "TOPIC")
                            HookFunctionTopic(msg);
                        else if (msg.GetCommand() == "MODE")
                            HookFunctionMode(msg);

                        /* BaseMessage baseMessage;
                        if (ParseBaseMessage(curr_event.ident, read_buffer[curr_event.ident], baseMessage))
                        {
                            // ignore request;
                            continue;
                        } */
                        // TODO 2 : handle message
>>>>>>> Stashed changes
                    }
                }
            }
            else if (curr_event.filter == EVFILT_WRITE)
            {
                /* send data to client */
                std::map<int, std::string>::iterator it = read_buffer.find(curr_event.ident);
                if (it != read_buffer.end())
                {
<<<<<<< Updated upstream
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
=======
                    if (read_buffer[curr_event.ident] != "")
                    {
                        int n;
                        if ((n = write(curr_event.ident, read_buffer[curr_event.ident].c_str(), read_buffer[curr_event.ident].size()) == -1))
                        {
                            std::cout << "client write error!" << std::endl;
                            std::vector<Socket>::iterator it = std::find(client_sockets.begin(), client_sockets.end(), curr_event.ident);
                            if (it != client_sockets.end())
                                client_sockets.erase(it);
                        }
                        else
                        {
                            read_buffer[curr_event.ident].clear();
>>>>>>> Stashed changes
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