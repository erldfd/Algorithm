#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    unordered_map<string, int> WantListMap;
    unordered_set<string> CanBuySet;

    int TotalDiscountDays = discount.size();

    for(int i =0; i < want.size(); ++i)
    {
        WantListMap[want[i]] = number[i]; 
    }
    
    for(int i = 0; i < 10; ++i)
    {
        if(WantListMap.find(discount[i]) == WantListMap.end())
        {
            continue;
        }
        
        WantListMap[discount[i]]--;
        
        if(WantListMap[discount[i]] <= 0)
        {
            CanBuySet.insert(discount[i]);
        }
    }
    
    int answer = 0;

    if(CanBuySet.size() == want.size())
    {
        answer = 1;
    }
    
    for(int i = 1; i < discount.size(); ++i)
    {
        if(i + 9 < discount.size() && WantListMap.find(discount[i + 9]) != WantListMap.end())
        {
            WantListMap[discount[i + 9]]--;

            if(WantListMap[discount[i + 9]] <= 0)
            {
                CanBuySet.insert(discount[i + 9]);
            }
        }
        
        if(WantListMap.find(discount[i-1]) != WantListMap.end())
        {
            WantListMap[discount[i-1]]++;

            if(WantListMap[discount[i-1]] > 0)
            {
                CanBuySet.erase(discount[i-1]);
            }
        }

        if(CanBuySet.size() == want.size())
        {
            answer++;
        }
    }
    
    return answer;
}