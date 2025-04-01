#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<int>& Nums, int Target)
{
	// currentNum, Index
	vector<pair<int, int>> DFSVector;
	DFSVector.push_back({ Nums[0], 0 });
	DFSVector.push_back({ -Nums[0], 0 });

	int TargetCount = 0;
	int MaxIndex = Nums.size() - 1;

	while (DFSVector.empty() == false)
	{
		auto [CurrentNum, CurrentIndex] = DFSVector.back();
		DFSVector.pop_back();

		if (CurrentIndex == MaxIndex)
		{
			if (CurrentNum == Target)
			{
				TargetCount++;
			}

			continue;
		}

		DFSVector.push_back({ CurrentNum + Nums[CurrentIndex + 1], CurrentIndex + 1 });
		DFSVector.push_back({ CurrentNum - Nums[CurrentIndex + 1], CurrentIndex + 1 });
	}

	return TargetCount;
}

int solution(vector<int> numbers, int target)
{
	return DFS(numbers, target);
}