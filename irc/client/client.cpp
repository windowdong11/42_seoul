// Client side C program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 3000

int main()
{
	int status, valread, client_fd;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "\n Socket creation error \n";
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		std::cout << "\nInvalid address/ Address not supported \n";
		return -1;
	}

	if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
												sizeof(serv_addr))) < 0)
	{
		std::cout << "\nConnection Failed \n";
		return -1;
	}
	std::string str;
	while (std::getline(std::cin, str))
	{
		send(client_fd, str.c_str(), str.length(), 0);
		// (void)valread;
		if (str == "send")
		{
			valread = read(client_fd, buffer, 1024 - 1); // subtract 1 for the null-terminator at the end
			std::cout << "from server : " << buffer << std::endl;
		}
		else if (str == "end")
			break;
	}

	close(client_fd);
	return 0;
}
