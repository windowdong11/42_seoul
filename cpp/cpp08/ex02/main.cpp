#include "MutantStack.hpp"
#include <iostream>
#include <list>

template<typename T, typename Container>
void printMutantStack(const MutantStack<T, Container>& stack)
{
	typename MutantStack<T, Container>::const_iterator it = stack.begin();
	typename MutantStack<T, Container>::const_iterator end = stack.end();
	while (it != end)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << '\n';
}

int main()
{
	MutantStack<int> stack;
	for (int i = 0; i < 10; ++i)
	{
		stack.push(i);
	}
	stack.pop();
	std::cout << "[stack]\n";
	printMutantStack(stack);
	MutantStack<int> copied_constructor(stack);
	std::cout << "[copy by constructor]\n";
	printMutantStack(copied_constructor);
	std::cout << "[copied]\n";
	MutantStack<int> copied;
	copied = stack;
	printMutantStack(copied);
	std::cout << "[list]\n";
	MutantStack<int, std::list<int> > list_stack;
	for(int i = 0; i < 10; ++i)
	{
		list_stack.push(i);
	}
	printMutantStack(list_stack);
	return 0;
}