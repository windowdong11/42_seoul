#ifndef ARRAY_HPP
#define ARRAY_HPP

/* include */
#include <stdexcept>

template <typename T>
class Array
{
private:
	typedef unsigned int index_t;
public:
	Array();							 // Creates an empty array
	Array(index_t n); // Creates an array of n elements initialized by default
	// copy : modifying either the original array or its copy after copying musn't affect the other array
	Array(const Array &rhs);
	Array<T> &operator=(const Array &rhs);
	~Array();

	T operator[](index_t i) const {
		if (i >= mCapacity)
		{
			throw std::out_of_range("out of range");
		}
		return mArray[i];
	}
	T& operator[](index_t i) {
		if (i >= mCapacity)
		{
			throw std::out_of_range("out of range");
		}
		return mArray[i];
	}

	index_t size() const {
		return mCapacity;
	}

private:
	T *mArray;
	index_t mCapacity;

	void deepCopyFrom(const Array<T>& rhs)
	{
		if (mArray != NULL)
		{
			delete[] mArray;
		}
		mArray = new T[rhs.mCapacity];
		for (index_t i = 0; i < rhs.mCapacity; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
		mCapacity = rhs.mCapacity;
	}
};

template <typename T>
Array<T>::Array()
		: mArray(NULL), mCapacity(0)
{
}

template <typename T>
Array<T>::Array(Array::index_t n)
		: mArray(new T[n]()), mCapacity(n)
{
}

template <typename T>
Array<T>::Array(const Array &rhs)
{
	deepCopyFrom(rhs);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	deepCopyFrom(rhs);
	return *this;
}

template <typename T>
inline Array<T>::~Array()
{
	if (mArray != NULL)
	{
		delete[] mArray;
	}
}

#endif
