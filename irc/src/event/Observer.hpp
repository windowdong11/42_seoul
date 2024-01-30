#ifndef OBSERVER_HPP
# define OBSERVER_HPP

/* include headers */

template <typename E>
class Observer
{
public:
  virtual void notify(E event) = 0;
};

#endif
