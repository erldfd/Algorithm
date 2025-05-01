#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> Types(nums.begin(), nums.end());
    int MaxCount = nums.size() / 2;
    
    return min((int)Types.size(), MaxCount);
}