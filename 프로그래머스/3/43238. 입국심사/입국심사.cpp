#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) 
{
    sort(times.begin(), times.end());
    
    long long Left = (long long)times[0];
    long long Right = (long long)times.back() * n;
    long long answer = Right;
    
    while(Left <= Right)
    {
        long long Mid = (Left + Right) / 2;
        long long PassCount = 0;
        
        for(int i = 0; i < times.size(); ++i)
        {
            PassCount += Mid / (long long)times[i];
        }
        
        if(PassCount >= n)
        {
            Right = Mid - 1;
            if(Mid < answer)
            {
                answer = Mid;
            }
        }
        else
        {
            Left = Mid + 1;
        }
    }
    
    return answer;
}