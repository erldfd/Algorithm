#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int Wins[]{6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    unordered_set<int> nums(win_nums.begin(), win_nums.end());
    
    int MaxCount = 0;
    int MinCount = 0;
    for(int l : lottos)
    {
        if(nums.find(l) == nums.end())
        {
            if(l == 0)
            {
                MaxCount++;
            }
        }
        else
        {
            MaxCount++;
            MinCount++;
        }
    }

    return {Wins[MaxCount], Wins[MinCount]};
}