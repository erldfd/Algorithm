#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<int> PrimeCacheSet;

bool IsPrime(int Number)
{
    if(Number == 0 || Number == 1)
    {
        return false;
    }
    
    if(PrimeCacheSet.find(Number) != PrimeCacheSet.end())
    {
        return true;
    }
    
    for(int i = 2; i*i <= Number; ++i)
    {
        if(Number % i == 0)
        {
            return false;
        }
    }
    
    PrimeCacheSet.insert(Number);
    return true;
}

int solution(string numbers) 
{
    PrimeCacheSet.insert(2);
    
    sort(numbers.begin(), numbers.end());
    unordered_set<string> Cache;

    int answer = 0;
    
    do
    {
        string NumberStr = "";
        
        for(auto& number : numbers)
        {
            NumberStr += number;
            
            if(NumberStr[0] == '0')
            {
                break;
            }
            
            if(Cache.find(NumberStr) != Cache.end())
            {
                continue;
            }
            
            if(IsPrime(stoi(NumberStr)))
            {
                answer++;
            }
            
            Cache.insert(NumberStr);
        }

    }while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return answer;
}