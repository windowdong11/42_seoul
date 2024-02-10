#ifndef EVENTQUEUE_HPP
#define EVENTQUEUE_HPP

/* include headers */
#include <sys/types.h>
#include <sys/event.h>
#include <exception>
#include <vector>
#include "Subject.hpp"



class Kevent : public kevent
{
  public:
    Kevent(int fd, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
    {
      EV_SET(this, fd, filter, flags, fflags, data, udata);
    }
    bool isReadable() const
    {
      return (filter == EVFILT_READ);
    }
    bool isWritable() const
    {
      return (filter == EVFILT_WRITE);
    }
};

class EventQueue
    // : public Subject<Kevent>
{
public:
  EventQueue();
  ~EventQueue();
  void addReadEvent(int target_fd);
  void addWriteEvent(int target_fd);
  void removeReadEvent(int target_fd);
  void removeWriteEvent(int target_fd);
  void dispatchEvent();

  int getEvents(struct kevent *event_buf, int size);
private:
  int mKq;
  std::vector<struct kevent> mChangeList;
};

class KeventObserver
    : public Observer<Kevent>
{
public:
  KeventObserver(EventQueue &eventQueue, int fd)
      : mEventQueue(eventQueue), mFd(fd)
  {
    mEventQueue.addObserver(this);
  }
  ~KeventObserver()
  {
    mEventQueue.removeObserver(this);
  }
  void update(Kevent &event)
  {
    const uintptr_t fd = event.ident;
    if (fd == mFd)
    {
      if (event.isReadable())
      {
        // do something
        mEventQueue.addReadEvent(fd);
      }
      else if (event.isWritable())
      {
        // do something
      }
    }
  }

private:
  EventQueue &mEventQueue;
  int mFd;
};

#endif
