#include "Span.hpp"
#include <iostream>

int main() 
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << ">> custom test set << \n";
	Span span(10000);
	// span.addNumber(10);
	// span.addNumber(1);
	try {
		std::cout << span.shortestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "[shortestSpan] caught exception : " << e.what() << '\n';
	}
	try {
		std::cout << span.longestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cout << "[shortestSpan] caught exception : " << e.what() << '\n';
	}
	span.fillWithRandomNumbers(1000000);
	try {
		span.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "[addNumber] caught exception : " << e.what() << '\n';
	}
	std::cout << "longest : " << span.shortestSpan() << '\n';
	std::cout << "shortest : " << span.longestSpan() << '\n';
	std::cout << ">>copied<<\n";
	const Span copied(span);
	std::cout << "longest : " << copied.shortestSpan() << '\n';
	std::cout << "shortest : " << copied.longestSpan() << '\n';
	return 0;
}