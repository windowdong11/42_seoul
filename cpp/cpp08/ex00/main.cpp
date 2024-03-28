#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<int> v;
	for(int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	std::vector<int>::iterator it;
	it = easyfind(v, 1);
	if (it != v.end())
		std::cout << "found : " << *it << '\n';
	else
		std::cout << "not found. end() returned\n";
	it = easyfind(v, 9999);
	if (it != v.end())
		std::cout << "found : " << *it << '\n';
	else
		std::cout << "not found. end() returned\n";
	const std::vector<int> cv(10, 1);
	std::cout << "compiled : " << *easyfind(cv, 1) << '\n';
	return 0;
}