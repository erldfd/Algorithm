#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;
    
    while(n >= a)
    {
        int CokeCount = (n / a) * b;
        n %= a;
        n += CokeCount;
        answer += CokeCount;
    }
    
    return answer;
}