#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 1;
    
    char x = s[0];
    int XCount = 1;
    int OtherCount = 0;
    
    for(int i = 1; i < s.size() - 1; ++i)
    {
        if(s[i] == x)
        {
            XCount++;
        }
        else
        {
            OtherCount++;
        }
        
        if(XCount == OtherCount)
        {
            answer++;
            x = s[i + 1];
            XCount = 0;
            OtherCount = 0;
        }
    }
    
    return answer;
}