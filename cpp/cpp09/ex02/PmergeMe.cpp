#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

namespace
{
	std::vector<std::size_t> getInsertionOrder(std::size_t size)
	{
		std::vector<std::size_t> result(size);
		std::size_t square = 2;
		std::size_t rangeEnd = 0;
		std::size_t order = 0;

		for (std::size_t i = 0; i < size; ++i)
		{
			if (i > rangeEnd)
			{
				square *= 2;
				rangeEnd = square - i - 1;
				if (rangeEnd >= size)
				{
					rangeEnd = size - 1;
				}
				order = rangeEnd;
			}
			result[i] = order--;
		}
		return (result);
	}
}

namespace VecMergeMe
{
	ContainerType getLosersByInsertionOrder(ContainerType::iterator begin, std::size_t loserCount, std::vector<std::size_t> &opponent, std::vector<std::size_t> &insertionOrder)
	{
		ContainerType losers(loserCount);
		for (std::size_t idx = 0; idx < loserCount; ++idx)
		{
			// 상대방의 인덱스를 구함
			const std::size_t indexBeforeSort = begin[insertionOrder[idx]].second;
			const std::size_t opponentIdx = opponent[indexBeforeSort];
			losers[idx] = begin[opponentIdx];
		}
		return losers;
	}

	void insertLosers(ContainerType::iterator begin, std::size_t winnerCount, std::size_t loserCount, ContainerType &losers, std::vector<std::size_t> &insertionOrder)
	{
		ContainerType::iterator lastSorted = begin + winnerCount;
		for (std::size_t idx = 0; idx < loserCount; ++idx)
		{
			ContainerType::iterator insertPosition = std::lower_bound(begin, begin + insertionOrder[idx] + idx, losers[idx]);
			std::copy_backward(insertPosition, lastSorted, lastSorted + 1);
			*insertPosition = losers[idx];
			++lastSorted;
		}
	}

	std::vector<std::size_t> matchPlayers(ContainerType::iterator begin, std::size_t winnerCount, bool isOdd)
	{
		std::vector<std::size_t> opponent(winnerCount + isOdd);
		const std::size_t opponentGap = winnerCount + isOdd; // 쌍을 이루는 상대방과 인덱스 상의 거리
		for (std::size_t idx = 0; idx < winnerCount; ++idx)
		{
			std::size_t opponentIdx = opponentGap + idx;
			opponent[idx] = opponentIdx;
			if (begin[idx].first < begin[opponentIdx].first)
			{
				std::swap(begin[idx], begin[opponentIdx]);
			}
		}
		if (isOdd)
		{
			opponent[winnerCount] = winnerCount;
		}
		return opponent;
	}
	void storeNewIndex(ContainerType::iterator begin, ContainerType::iterator end)
	{
		for (std::size_t idx = 0; begin != end; ++begin, ++idx)
		{
			begin->second = idx;
		}
	}

	std::vector<std::size_t> storeIndex(ContainerType::iterator begin, std::size_t size)
	{
		std::vector<std::size_t> originalIndex(size);
		for (std::size_t idx = 0; idx < size; ++idx)
		{
			originalIndex[idx] = begin[idx].second;
		}
		return originalIndex;
	}

	void loadIndex(ContainerType::iterator begin, std::size_t size, std::vector<std::size_t> &originalIndex)
	{
		for (std::size_t idx = 0; idx < size; ++idx)
		{
			begin[idx].second = originalIndex[begin[idx].second];
		}
	}

	void print(ContainerType::iterator begin, ContainerType::iterator end)
	{
		for (; begin + 1 != end; ++begin)
		{
			std::cout << begin->first << ' ';
		}
		std::cout << begin->first;
		std::cout << '\n';
	}

	void tournamentSort(ContainerType::iterator begin, ContainerType::iterator end)
	{
		const std::size_t size = end - begin;
		if (size <= 1)
		{
			return;
		}
		// 쌍을 만들고 각 쌍마다 승자를 가림
		const std::size_t winnerCount = size / 2;
		std::vector<std::size_t> opponent = matchPlayers(begin, winnerCount, size % 2);
		// 기존 인덱스 저장
		std::vector<std::size_t> originalIndex = storeIndex(begin, size);
		// 새로운 인덱스 부여
		storeNewIndex(begin, end);
		// 재귀적으로 승자를 정렬
		tournamentSort(begin, begin + winnerCount);

		// 삽입할 순서대로 패자를 저장
		const std::size_t loserCount = size - winnerCount;
		std::vector<std::size_t> insertionOrder = getInsertionOrder(loserCount);
		ContainerType losers = getLosersByInsertionOrder(begin, loserCount, opponent, insertionOrder);
		// 패자 삽입
		insertLosers(begin, winnerCount, loserCount, losers, insertionOrder);
		// 이전 인덱스로 되돌림
		loadIndex(begin, size, originalIndex);
	}
}

namespace DequeMergeMe {
	ContainerType getLosersByInsertionOrder(ContainerType::iterator begin, std::size_t loserCount, std::vector<std::size_t> &opponent, std::vector<std::size_t> &insertionOrder)
	{
		ContainerType losers(loserCount);
		for (std::size_t idx = 0; idx < loserCount; ++idx)
		{
			// 상대방의 인덱스를 구함
			const std::size_t indexBeforeSort = begin[insertionOrder[idx]].second;
			const std::size_t opponentIdx = opponent[indexBeforeSort];
			losers[idx] = begin[opponentIdx];
		}
		return losers;
	}

	void insertLosers(ContainerType::iterator begin, std::size_t winnerCount, std::size_t loserCount, ContainerType &losers, std::vector<std::size_t> &insertionOrder)
	{
		ContainerType::iterator lastSorted = begin + winnerCount;
		for (std::size_t idx = 0; idx < loserCount; ++idx)
		{
			ContainerType::iterator insertPosition = std::lower_bound(begin, begin + insertionOrder[idx] + idx, losers[idx]);
			std::copy_backward(insertPosition, lastSorted, lastSorted + 1);
			*insertPosition = losers[idx];
			++lastSorted;
		}
	}

	std::vector<std::size_t> matchPlayers(ContainerType::iterator begin, std::size_t winnerCount, bool isOdd)
	{
		std::vector<std::size_t> opponent(winnerCount + isOdd);
		const std::size_t opponentGap = winnerCount + isOdd; // 쌍을 이루는 상대방과 인덱스 상의 거리
		for (std::size_t idx = 0; idx < winnerCount; ++idx)
		{
			std::size_t opponentIdx = opponentGap + idx;
			opponent[idx] = opponentIdx;
			if (begin[idx].first < begin[opponentIdx].first)
			{
				std::swap(begin[idx], begin[opponentIdx]);
			}
		}
		if (isOdd)
		{
			opponent[winnerCount] = winnerCount;
		}
		return opponent;
	}
	void storeNewIndex(ContainerType::iterator begin, ContainerType::iterator end)
	{
		for (std::size_t idx = 0; begin != end; ++begin, ++idx)
		{
			begin->second = idx;
		}
	}

	std::vector<std::size_t> storeIndex(ContainerType::iterator begin, std::size_t size)
	{
		std::vector<std::size_t> originalIndex(size);
		for (std::size_t idx = 0; idx < size; ++idx)
		{
			originalIndex[idx] = begin[idx].second;
		}
		return originalIndex;
	}

	void loadIndex(ContainerType::iterator begin, std::size_t size, std::vector<std::size_t> &originalIndex)
	{
		for (std::size_t idx = 0; idx < size; ++idx)
		{
			begin[idx].second = originalIndex[begin[idx].second];
		}
	}

	void print(ContainerType::iterator begin, ContainerType::iterator end)
	{
		for (; begin + 1 != end; ++begin)
		{
			std::cout << begin->first << ' ';
		}
		std::cout << begin->first;
		std::cout << '\n';
	}

	void tournamentSort(ContainerType::iterator begin, ContainerType::iterator end)
	{
		const std::size_t size = end - begin;
		if (size <= 1)
		{
			return;
		}
		// 쌍을 만들고 각 쌍마다 승자를 가림
		const std::size_t winnerCount = size / 2;
		std::vector<std::size_t> opponent = matchPlayers(begin, winnerCount, size % 2);
		// 기존 인덱스 저장
		std::vector<std::size_t> originalIndex = storeIndex(begin, size);
		// 새로운 인덱스 부여
		storeNewIndex(begin, end);
		// 재귀적으로 승자를 정렬
		tournamentSort(begin, begin + winnerCount);

		// 삽입할 순서대로 패자를 저장
		const std::size_t loserCount = size - winnerCount;
		std::vector<std::size_t> insertionOrder = getInsertionOrder(loserCount);
		ContainerType losers = getLosersByInsertionOrder(begin, loserCount, opponent, insertionOrder);
		// 패자 삽입
		insertLosers(begin, winnerCount, loserCount, losers, insertionOrder);
		// 이전 인덱스로 되돌림
		loadIndex(begin, size, originalIndex);
	}
}