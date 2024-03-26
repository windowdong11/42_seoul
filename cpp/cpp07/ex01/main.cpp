#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T& i)
{
	std::cout << i << std::endl;
}

int main()
{
	const int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, print);
	std::string strarr[] = {"one", "two", "three", "four", "five"};
	::iter(strarr, 5, print);
}