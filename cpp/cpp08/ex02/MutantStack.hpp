#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* include */
#include <stack>
#include <vector>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
		MutantStack();
		MutantStack(const MutantStack& rhs);
		MutantStack& operator=(const MutantStack& rhs);
		~MutantStack();
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
private:
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
	: std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &rhs)
	: std::stack<T, Container>(rhs)
{
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &rhs)
{
	if (this != &rhs)
	{
		std::stack<T, Container>::operator=(rhs);
	}
	return *this;
}

template <typename T, typename Container>
inline MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

#endif