#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ctime>

Span::Span()
		: mCapacity(0), mLength(0), mArray(NULL)
{
	std::srand(std::time(NULL));
}

Span::Span(unsigned int N)
		: mCapacity(N), mLength(0), mArray(new int[N]())
{
	std::srand(std::time(NULL));
}

Span::Span(const Span &rhs)
		: mCapacity(rhs.mCapacity), mLength(rhs.mLength), mArray(new int[rhs.mCapacity]())
{
	for (size_t idx = 0; idx < rhs.mLength; ++idx)
	{
		mArray[idx] = rhs.mArray[idx];
	}
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		if (mArray != NULL)
		{
			delete[] mArray;
		}
		mCapacity = rhs.mCapacity;
		mLength = rhs.mLength;
		mArray = new int[rhs.mCapacity]();
		for (size_t idx = 0; idx < rhs.mLength; ++idx)
		{
			mArray[idx] = rhs.mArray[idx];
		}
	}
	return *this;
}

Span::~Span()
{
	delete[] mArray;
}

void Span::addNumber(int num)
{
	if (mLength == mCapacity)
	{
		throw std::runtime_error("Capacity limit exceeded.");
	}

	mArray[mLength] = num;
	++mLength;
}

int Span::shortestSpan() const
{
	if (mLength < 2)
	{
		throw std::runtime_error("Not enough elements. Need more than 2.");
	}

	std::sort(mArray, mArray + mLength);
	int minDiff = std::numeric_limits<int>::max();
	idx_t end = mLength - 1;
	for (idx_t i = 0; i < end; ++i)
	{
		const int diff = mArray[i + 1] - mArray[i];
		minDiff = std::min(diff, minDiff);
	}
	return minDiff;
}

int Span::longestSpan() const
{
	if (mLength < 2)
	{
		throw std::runtime_error("Not enough elements. Need more than 2.");
	}

	const int maxValue = *std::max_element(mArray, mArray + mLength);
	const int minValue = *std::min_element(mArray, mArray + mLength);
	return maxValue - minValue;
}

/*
Fill all elements with random numbers.
Previously stored values are not saved.
*/
void Span::fillWithRandomNumbers(int limit)
{
	std::cout << "fill span with : ";
	for (idx_t i = 0; i < mCapacity; ++i)
	{
		mArray[i] = std::rand() % limit;
		std::cout << mArray[i] << ' ';
	}
	std::cout << '\n';
	mLength = mCapacity;
}
