#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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

typedef std::pair<int, int> Pair;

void printVec(std::vector<Pair>::iterator begin, std::vector<Pair>::iterator end)
{
	assert(std::distance(begin, end) >= 0);
	for (; begin != end; ++begin)
	{
		std::cout << begin->first << ' ';
	}
	std::cout << '\n';
}

void tournamentSort(std::vector<Pair>::iterator begin, std::vector<Pair>::iterator end)
{
	const std::size_t size = end - begin;
	assert(std::distance(begin, end) >= 0);
	std::cout << "sort " << size << '\n';
	if (size <= 1)
	{
		std::cout << "insert\n";
		return ;
	}
	// 쌍을 만듬
	const std::size_t winnerCount = size / 2;
	const std::size_t loserCount = size - winnerCount;
	std::vector<std::size_t> opponent(winnerCount + size % 2);
	const std::size_t opponentGap = size / 2 + size % 2;
	for (std::size_t idx = 0; idx < winnerCount; ++idx)
	{
		std::size_t opponentIdx = idx + size % 2;
		opponent[idx] = opponentIdx;
		// 각 쌍마다 승자를 가림
		if (begin[idx].first > begin[idx + opponentGap].first)
		{
			std::swap(begin[idx], begin[idx + opponentGap]);
		}
	}
	if (size % 2 != 0)
	{
		opponent[winnerCount] = 0;
	}
	std::cout << "oppo : ";
	for (std::size_t idx = 0; idx < winnerCount + size % 2; ++idx)
	{
		std::cout << opponent[idx] << ' ';
	}
	std::cout << '\n';
	// 기존 인덱스 저장
	std::vector<int> originalIndex(size);
	for (std::size_t idx = 0; idx < size; ++idx)
	{
		originalIndex[idx] = begin[idx].second;
		// 새로운 인덱스 부여
		begin[idx].second = idx;
	}
	// 재귀적으로 승자를 정렬
	std::cout << "match\n";
	printVec(begin, begin + winnerCount);
	printVec(begin + winnerCount, end);
	std::cout << "--------------------\n";
	std::sort(begin, begin + winnerCount);
	printVec(begin, begin + winnerCount);
	printVec(begin + winnerCount, end);
	std::cout << "--------------------\n";
	// tournamentSort(begin, begin + winnerCount);
	// 삽입할 순서대로 패자를 저장
	std::vector<Pair> losers(loserCount);
	std::vector<std::size_t> insertionOrder = getInsertionOrder(loserCount);
	std::vector<Pair>::iterator loserIter = losers.begin();
	for (std::size_t idx = 0; idx < loserCount; ++idx)
	{
		std::cout << "winner : " << begin[insertionOrder[idx]].first << ", loser: " << begin[opponent[begin[insertionOrder[idx]].second] + size / 2].first << '\n';
		*loserIter = begin[opponent[begin[insertionOrder[idx]].second] + size / 2];
		++loserIter;
	}
	std::cout << "losers ordered by winner\n";
	printVec(begin, begin + winnerCount);
	printVec(losers.begin(), losers.end());
	std::cout << "--------------------\n";
	// 이전 인덱스로 되돌림
	for (std::size_t idx = 0; idx < size; ++idx)
	{ㄲ
		begin[idx].second = originalIndex[begin[idx].second];
	}
	// 패자 삽입
	for (std::size_t idx = 0; idx < loserCount; ++idx)
	{
		std::vector<Pair>::iterator insertPosition = std::lower_bound(begin, begin + insertionOrder[idx], losers[idx]);
		std::rotate()
		// std::insert(insertPosition, losers[idx]);
		// *insertPosition = losers[idx];
	}
	printVec(begin, end);
}

int main(int argc, char *argv[])
{

	int arr[] = {4, 1, 2, 6, 5, 0, 3};
	std::vector<Pair> list(sizeof(arr) / sizeof(int));
	for (std::size_t idx = 0; idx < list.size(); ++idx)
	{
		list[idx] = std::make_pair(arr[idx], idx);
	}

	std::cout << "Original List:\n";
	printVec(list.begin(), list.end());
	tournamentSort(list.begin(), list.end());

	std::cout << "Sorted List:\n";
	printVec(list.begin(), list.end());

	return 0;
}