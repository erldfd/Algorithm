#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    
    for(int i = 1; i <= number; ++i)
    {
        int Count = 0;
        
        for(int j = 1; j*j <= i; ++j)
        {
            if(i % j != 0)
            {
                continue;
            }
            
            if(j*j == i)
            {
                Count++;
            }
            else
            {
                Count += 2;
            }
        }
        
        answer += (Count > limit) ? power : Count;
    }
    
    return answer;
}