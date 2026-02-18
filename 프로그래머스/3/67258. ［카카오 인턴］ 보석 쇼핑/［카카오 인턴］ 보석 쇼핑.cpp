#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    unordered_map<string, int> Map;
    for(const string& g : gems)
    {
        Map[g]++;
    }
    
    const int TotalTypeCount = Map.size();
    
    int MinLength = 2000000000;
    int Length = 0;
    Map.clear();
    
    int FrontIndex = 0;
    int BackIndex = 0;
    
    int MinFrontIndex = 0;
    int MinBackIndex = 0;

    Map[gems.front()]++;
    while(gems.size() > BackIndex && (gems.size() - BackIndex >= TotalTypeCount))
    {
        Length = FrontIndex - BackIndex;

        if(Map.size() == TotalTypeCount && MinLength > Length)
        {
            MinLength = Length;
            MinFrontIndex = FrontIndex;
            MinBackIndex = BackIndex;
        }
        
        if(Map.size() < TotalTypeCount)
        {
            if(FrontIndex < gems.size() - 1)
            {
                FrontIndex++;
                Map[gems[FrontIndex]]++;
            }
            else
            {
                Map[gems[BackIndex]]--;
                if(Map[gems[BackIndex]] == 0)
                {
                    Map.erase(gems[BackIndex]);
                }

                BackIndex++;
            }
        }
        else
        {
            Map[gems[BackIndex]]--;
            if(Map[gems[BackIndex]] == 0)
            {
                Map.erase(gems[BackIndex]);
            }
            
            BackIndex++;
        }
    }
    
    return {MinBackIndex + 1, MinFrontIndex + 1};
}