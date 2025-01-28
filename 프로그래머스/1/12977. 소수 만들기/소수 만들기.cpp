#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> PrimeSet;

bool IsPrime(int num)
{
    if(PrimeSet.find(num) != PrimeSet.end())
    {
        return true;
    }
    
    for(int i = 2; i*i <= num; ++i)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    
    return true;
    
}


int solution(vector<int> nums) 
{
    PrimeSet.insert(2);
    PrimeSet.insert(3);
    
    int answer = 0;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i+1; j < nums.size(); ++j)
        {
            for(int k = j+1; k < nums.size(); ++k)
            {
                if(IsPrime(nums[i] +nums[j] + nums[k]))
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}