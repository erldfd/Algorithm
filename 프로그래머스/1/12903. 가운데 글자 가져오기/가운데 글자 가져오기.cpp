#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    int length = s.size();
    string answer = "";
    
    int half = length / 2;
    
    if (length % 2 == 0)
    {
        answer += s[half - 1];
        answer += s[half];
    }
    else
    {
        answer += s[half];
    }
    
    return answer;
}