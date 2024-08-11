#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

/*
This template function performs a linear search on linear containers (such as std::vector, std::list) to find a given value `n`. 

Returns:
- If the value `n` is found within the container, it returns an iterator to the found element.
- If the value is not found, it returns an iterator to `container.end()`, indicating the end of the container.
*/
template <typename LinearContainer>
typename LinearContainer::iterator easyfind(LinearContainer& container, int n)
{
	return std::find(container.begin(), container.end(), n);
}

template <typename LinearContainer>
typename LinearContainer::const_iterator easyfind(const LinearContainer& container, int n)
{
	return std::find(container.begin(), container.end(), n);
}

#endif