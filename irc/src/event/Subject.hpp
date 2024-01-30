#ifndef SUBJECT_HPP
# define SUBJECT_HPP

/* include headers */
#include <vector>
#include "Observer.hpp"


/* E : event type */
template <typename E>
class Subject
{
public:
  Subject(){};
  Subject(const Subject &other)
      : mObservers(other.mObservers){};
  ~Subject(){};
  Subject &operator=(const Subject &other)
  {
    if (this != &other)
    {
      mObservers = other.mObservers;
    }
    return (*this)
  };
  void addObserver(Observer<E> *observer);
  void removeObserver(Observer<E> *observer);
  void notifyObservers(int fd, E event);

private:
  std::vector<Observer<E> *> mObservers;
};

#endif
