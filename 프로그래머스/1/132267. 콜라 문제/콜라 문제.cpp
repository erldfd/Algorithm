#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int TotalCount = 0;
    
    while(n >= a)
    {
        int NewCount = (n / a) * b;
        n = (n % a) + NewCount;
        TotalCount += NewCount;
    }
    
    return TotalCount;
}