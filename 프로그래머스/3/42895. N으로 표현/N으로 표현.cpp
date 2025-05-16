#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MinValue = 9;
void DFS(int N, int Goal, int UseCount, int CurrentNumber)
{
    if(CurrentNumber == Goal)
    {
        MinValue = min(MinValue, UseCount);
    }
    
    int Operand = 0;
    
    for(int i = 0; i < 9; ++i)
    {
        //Operand += N * 10 * i;
        Operand = Operand * 10 + N;
        int NewUseCount = UseCount + i + 1;
        if(NewUseCount > 8)
        {
            return;
        }
        
        DFS(N, Goal, NewUseCount, CurrentNumber + Operand);
        DFS(N, Goal, NewUseCount, CurrentNumber - Operand);
        
        if(CurrentNumber != 0)
        {
            DFS(N, Goal, NewUseCount, CurrentNumber * Operand);
            DFS(N, Goal, NewUseCount, CurrentNumber / Operand);
        }
    }
}

int solution(int N, int number) 
{
    DFS(N, number, 0, 0);
    return (MinValue > 8) ? -1 : MinValue;
}