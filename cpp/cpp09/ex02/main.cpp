#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cassert>
#include <ctime>
#include "PmergeMe.hpp"


int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "usage : ./PmergeMe <positive integer sequence>\n";
		std::cout << "example : ./PmergeMe 1 2 \"5\" 3\n";
		return 1;
	}
	VecMergeMe::ContainerType listVec(argc - 1);
	DequeMergeMe::ContainerType listDeque(argc - 1);
	for (int idx = 1; idx < argc; ++idx)
	{
		int num = std::atoi(argv[idx]);
		if (num <= 0)
		{
			std::cout << "Only positive integers are allowed.\n";
			return 1;
		}
		listVec[idx - 1] = std::make_pair(num, idx - 1);
		listDeque[idx - 1] = listVec[idx - 1];
	}

	std::cout << "Before: ";
	VecMergeMe::print(listVec.begin(), listVec.end());
	// sort by vector
	std::clock_t vecStart = std::clock();
	VecMergeMe::tournamentSort(listVec.begin(), listVec.end());
	std::clock_t vecEnd = std::clock();
	// sort by list
	std::clock_t listStart = std::clock();
	DequeMergeMe::tournamentSort(listDeque.begin(), listDeque.end());
	std::clock_t listEnd = std::clock();
	std::cout << "After: ";
	VecMergeMe::print(listVec.begin(), listVec.end());
	std::cout << "Time to process a range of 5 elements with std::vector : " << vecEnd - vecStart << " us\n";
	std::cout << "Time to process a range of 5 elements with std::deque : " << listEnd - listStart << " us\n";
	return 0;
}