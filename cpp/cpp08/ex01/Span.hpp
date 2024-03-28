#ifndef SPAN_HPP
# define SPAN_HPP

/* include */
#include <vector>

class Span
{
private:
		typedef unsigned int idx_t;
		Span();
public:
		Span(idx_t N);
		Span(const Span& rhs);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void fillWithRandomNumbers(int limit);
private:
	idx_t mCapacity;
	idx_t mLength;
	int *mArray;
};

#endif