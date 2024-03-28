#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* include */
#include <stack>
#include <vector>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
		MutantStack();
		MutantStack(const MutantStack& rhs);
		MutantStack& operator=(const MutantStack& rhs);
		~MutantStack();
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
private:
};

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &rhs)
	: std::stack<T>(rhs)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	return *this;
}

template <typename T>
inline MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

#endif