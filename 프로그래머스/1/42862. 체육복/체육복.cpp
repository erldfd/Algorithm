#include <string>
#include <vector>

using namespace std;

vector<bool> HasReserve(31, false);
vector<bool> HasLost(31, false);

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    for(int r : reserve)
    {
        HasReserve[r] = true;
    }
    
    for(int l : lost)
    {
        if(HasReserve[l])
        {
            HasReserve[l] = false;
        }
        else
        {
            HasLost[l] = true;
        }
    }
    
    int answer = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        if(HasLost[i])
        {
            if(HasReserve[i - 1])
            {
                HasReserve[i - 1] = false;
                HasLost[i] = false;
                answer++;
            }
            else if(i < n && HasReserve[i + 1])
            {
                HasReserve[i + 1] = false;
                HasLost[i] = false;
                answer++;
            }
        }
        else
        {
            answer++;
        }
    }
    
    return answer;
}