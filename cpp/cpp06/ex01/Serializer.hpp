#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/* include */
#include <stdint.h>
#include <string>

class Serializer
{
  public:
  struct Data
  {
    std::string name;
    int age;
  };

  ~Serializer();
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

  private:
  Serializer();
  Serializer(const Serializer &rhs);
  Serializer &operator=(const Serializer &rhs);
};

#endif