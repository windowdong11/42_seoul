#ifndef UNEQUIPPEDMANAGER_HPP
# define UNEQUIPPEDMANAGER_HPP

#include "AMateria.hpp"

class UnequippedManager
{
private:
	AMateria **materias;
	size_t capacity;
	size_t size;
	static size_t const defaultCapacity = 16;
	// Do not call this function
	UnequippedManager(const UnequippedManager& rhs) {
		(void)rhs;
	}
	// Do not call this function
	void operator=(const UnequippedManager& rhs) {
		(void)rhs;
	};
public:
	UnequippedManager() : materias(new AMateria*[defaultCapacity]), capacity(defaultCapacity), size(0) {
		for (size_t i = 0; i < capacity; i++)
			materias[i] = NULL;
	};
	~UnequippedManager() {
		for (size_t i = 0; i < size; i++)
			delete materias[i];
		delete[] materias;
	};
	void add(AMateria *materia) {
		if (size == capacity)
		{
			const size_t newCapacity = capacity * 2;
			AMateria **tmp = new AMateria*[newCapacity];
			for (size_t i = 0; i < capacity; i++)
				tmp[i] = materias[i];
			for (size_t i = capacity; i < newCapacity; i++)
				tmp[i] = NULL;
			delete[] materias;
			materias = tmp;
			capacity *= 2;
		}
		materias[size] = materia;
		size++;
	};
};

#endif