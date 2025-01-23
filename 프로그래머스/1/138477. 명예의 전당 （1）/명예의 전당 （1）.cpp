#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    vector<int> HOF;
    
    int WholeDaysCount = score.size();
    
    for(int i =0; i < WholeDaysCount; ++i)
    {
        
        if (HOF.size() < k)
        {
            HOF.push_back(score[i]);
        }
        else if(HOF.back() < score[i])
        {
            HOF.back() = score[i];
        }
        
        std::sort(HOF.rbegin(), HOF.rend());
        
        answer.push_back(HOF.back());
    }
    
    return answer;
}