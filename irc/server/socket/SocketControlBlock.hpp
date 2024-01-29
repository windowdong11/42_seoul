#ifndef SOCKETCONTROLBLOCK_HPP
#define SOCKETCONTROLBLOCK_HPP

/* include headers */

class SocketControlBlock
{
private:
	typedef int t_refCnt;
	int mSocket;
	t_refCnt mRefCnt;

	/* DO NOT CALL THIS */
	SocketControlBlock(){};
	/* DO NOT CALL THIS */
	SocketControlBlock(const SocketControlBlock &rhs) { (void)rhs; };
	/* DO NOT CALL THIS */
	SocketControlBlock &operator=(const SocketControlBlock &rhs) { (void)rhs; };

public:
	~SocketControlBlock(){};
	SocketControlBlock(int socket_fd) : mSocket(socket_fd), mRefCnt(1){};
	t_refCnt getRefCnt()
	{
		return mRefCnt;
	}
	void increaseRefCnt()
	{
		++mRefCnt;
	}
	void decreaseRefCnt()
	{
		--mRefCnt;
	}
	int getSocket()
	{
		return mSocket;
	}
	void setSocket(int socket_fd)
	{
		mSocket = socket_fd;
	}
};

#endif
