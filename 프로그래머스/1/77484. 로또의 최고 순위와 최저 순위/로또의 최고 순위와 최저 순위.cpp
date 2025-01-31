#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    int zeroCount =0;
    int winCount = 0;
    
    for(auto& num : lottos)
    {
        if(num == 0)
        {
            zeroCount++;
        }
        
        for(auto& winNum : win_nums)
        {
            if(num == winNum)
            {
                winCount++;
            }
        }
    }
    
    vector<int> answer;
    
    answer.push_back(clamp(7 - winCount - zeroCount, 1, 6));
    answer.push_back(clamp(7 - winCount, 1, 6));
    
    return answer;
}