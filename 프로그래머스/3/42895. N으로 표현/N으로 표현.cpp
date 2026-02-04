#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> Caches(9);

int UsingNumber;

unordered_set<int>& CalcChances(int UsingNumberCount)
{
    if(Caches[UsingNumberCount].empty() == false)
    {
        return Caches[UsingNumberCount];
    }
    
    int Operand = 0;
    for(int i = 0; i < UsingNumberCount; ++i)
    {
        Operand = Operand * 10 + UsingNumber;
    }
    
    unordered_set<int> AllChances;
    AllChances.insert(Operand);
    
    for(int i = 1; i < UsingNumberCount; ++i)
    {
        int j = UsingNumberCount - i;
        
        const unordered_set<int>& Chances1 = CalcChances(i);
        const unordered_set<int>& Chances2 = CalcChances(j);
        
        for(int Chance1 : Chances1)
        {
            for(int Chance2 : Chances2)
            {
                AllChances.insert(Chance1 + Chance2);
                AllChances.insert(Chance1 - Chance2);
                AllChances.insert(Chance1 * Chance2);
                if(Chance2 != 0)
                {
                    AllChances.insert(Chance1 / Chance2);
                }
            }
        }
    }
    
    Caches[UsingNumberCount] = AllChances;
    return Caches[UsingNumberCount];
}

int solution(int N, int number) 
{
    UsingNumber = N;
    
    int answer = -1;
    
    for(int i = 1; i <= 8; ++i)
    {
        const unordered_set<int>& Chances = CalcChances(i);
        if(Chances.find(number) == Chances.end())
        {
            continue;
        }
        
        answer = i;
        break;
    }
    
    return answer;
}
