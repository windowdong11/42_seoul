#include "EventQueue.hpp"
#include <unistd.h>

EventQueue::EventQueue()
		: mKq(kqueue())
{
	if (mKq == -1)
		throw std::runtime_error("Failed to initialize.");
}

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

EventQueue::~EventQueue()
{
	close(mKq);
}

void EventQueue::dispatchEvent()
{
	struct kevent event_list[10];
	int eventCnt = getEvents(event_list, 10);
	for (int i = 0; i < eventCnt; ++i)
	{
		if (event_list[i].filter == EVFILT_READ)
		{
			// notifyObservers(q_read, event_list[i]);
		}
		else if (event_list[i].filter == EVFILT_WRITE)
		{
			// notifyObservers(q_write, event_list[i]);
		}
	}
}

int EventQueue::getEvents(struct kevent *event_buf, int size)
{
	int result = kevent(mKq, &mChangeList[0], mChangeList.size(), event_buf, size, NULL);
	mChangeList.clear();
	if (result == -1)
		throw std::runtime_error("Failed to get events.");
	return result;
}
