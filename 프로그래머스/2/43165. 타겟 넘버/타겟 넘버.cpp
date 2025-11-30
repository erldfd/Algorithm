#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> Combination;

int GetTargetCount(int PlusCount, int Target, const vector<int>& numbers)
{
    for(int i = 0; i < PlusCount; ++i)
    {
        Combination[numbers.size() - 1 - i] = true;
    }
    
    int Result = 0;
    do
    {
        int CurrentNumber = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            CurrentNumber += (Combination[i]) ? numbers[i] : -numbers[i];
        }
        
        if(CurrentNumber == Target)
        {
            Result++;
        }
        
    }while(next_permutation(Combination.begin(), Combination.end()));
    
    return Result;
}

int solution(vector<int> numbers, int target) 
{
    Combination.resize(numbers.size(), false);
    
    int answer = 0;
    
    for(int i = 0; i <= numbers.size(); ++i)
    {
        answer += GetTargetCount(i, target, numbers);
    }
    
    return answer;
}