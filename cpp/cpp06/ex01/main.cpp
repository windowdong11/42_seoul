#include "Serializer.hpp"
#include <iostream>

int main()
{
  Serializer::Data data;
  data.name = "John";
  data.age = 42;
  uintptr_t raw = Serializer::serialize(&data);
  Serializer::Data *ptr = Serializer::deserialize(raw);
  std::cout << "Name: " << ptr->name << std::endl;
  std::cout << "Age: " << ptr->age << std::endl;
  return 0;
}