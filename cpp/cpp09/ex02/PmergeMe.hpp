#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/* include */
#include <vector>
#include <deque>
#include <algorithm>

namespace CommonMergeMe
{
	typedef std::pair<int, std::size_t> Pair;
}

namespace VecMergeMe
{
	typedef std::vector<CommonMergeMe::Pair> ContainerType;
	ContainerType getLosersByInsertionOrder(ContainerType::iterator begin, std::size_t loserCount, std::vector<std::size_t> &opponent, std::vector<std::size_t> &insertionOrder);
	void insertLosers(ContainerType::iterator begin, std::size_t winnerCount, std::size_t loserCount, ContainerType &losers, std::vector<std::size_t> &insertionOrder);
	std::vector<std::size_t> matchPlayers(ContainerType::iterator begin, std::size_t winnerCount, bool isOdd);
	void storeNewIndex(ContainerType::iterator begin, ContainerType::iterator end);
	std::vector<std::size_t> storeIndex(ContainerType::iterator begin, std::size_t size);
	void loadIndex(ContainerType::iterator begin, std::size_t size, std::vector<std::size_t> &originalIndex);
	void print(ContainerType::iterator begin, ContainerType::iterator end);
	void tournamentSort(ContainerType::iterator begin, ContainerType::iterator end);
}

namespace DequeMergeMe
{
	typedef std::deque<CommonMergeMe::Pair> ContainerType;
	ContainerType getLosersByInsertionOrder(ContainerType::iterator begin, std::size_t loserCount, std::vector<std::size_t> &opponent, std::vector<std::size_t> &insertionOrder);
	void insertLosers(ContainerType::iterator begin, std::size_t winnerCount, std::size_t loserCount, ContainerType &losers, std::vector<std::size_t> &insertionOrder);
	std::vector<std::size_t> matchPlayers(ContainerType::iterator begin, std::size_t winnerCount, bool isOdd);
	void storeNewIndex(ContainerType::iterator begin, ContainerType::iterator end);
	std::vector<std::size_t> storeIndex(ContainerType::iterator begin, std::size_t size);
	void loadIndex(ContainerType::iterator begin, std::size_t size, std::vector<std::size_t> &originalIndex);
	void print(ContainerType::iterator begin, ContainerType::iterator end);
	void tournamentSort(ContainerType::iterator begin, ContainerType::iterator end);
}

#endif
