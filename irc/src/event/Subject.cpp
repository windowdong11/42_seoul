#include "Subject.hpp"

template <typename E>
Subject<E>::Subject(){};

template <typename E>
Subject<E>::Subject(const Subject &other)
    : mObservers(other.mObservers){};
template <typename E>
Subject<E>::~Subject(){};

template <typename E>
Subject<E> &Subject<E>::operator=(const Subject<E> &other)
{
  if (this != &other)
  {
    mObservers = other.mObservers;
  }
  return (*this)
};

template <typename E>
void Subject<E>::addObserver(Observer<E> *observer)
{
  mObservers.push_back(observer);
}

template <typename E>
void Subject<E>::removeObserver(Observer<E> *observer)
{
  mObservers.erase(std::remove(mObservers.begin(), mObservers.end(), observer), mObservers.end());
}

template <typename E>
void Subject<E>::notifyObservers(int fd, E event)
{
  for (auto observer : mObservers)
  {
    observer->notify(fd, event);
  }
}