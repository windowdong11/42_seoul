#include "Array.hpp"
#include <iostream>
#include <exception>

int main()
{
	Array<int> array(9);
	std::cout << "size : " << array.size() << '\n';
	array[0] = 0;
	array[1] = 1;
	array[0] = array[0];
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " : ";
		try
		{
			array[i] = array[i - 2] + array[i - 1];
			std::cout << "sum ok" << '\n';
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << "[print all]\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " : ";
		try
		{
			std::cout << array[i] << '\n';
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	// const Array<int> ca(5);
	// ca[0] = 1;
	return 0;
}