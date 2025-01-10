#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) 
{
    string samjinbubStr = "";
    
    while(n > 0)
    {
        samjinbubStr+= n % 3 + '0';
        n /= 3;
    }
    
    int answer = 0;
    
    for(int i = 0; i < samjinbubStr.size(); ++i)
    {
        answer += (samjinbubStr[samjinbubStr.size() - 1 - i] - '0') * pow(3, i);
    }
    
    return answer;
}