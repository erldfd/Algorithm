#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int roundCount = 1;
    
    int large = max(a, b);
    
    while(abs(a-b) != 1 || large % 2 != 0)
    {
        if(a%2 == 0)
        {
            a/=2;
        }
        else
        {
            a/=2;
            a++;
        }
        
        if(b%2 == 0)
        {
            b/=2;
        }
        else
        {
            b/=2;
            b++;
        }
        
        roundCount++;
        large = max(a, b);
    }
    
    return roundCount;
}