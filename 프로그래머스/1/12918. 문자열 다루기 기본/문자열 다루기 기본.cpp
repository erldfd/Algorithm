#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsNumberOnly(const string& s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            continue;
        }

        return false;
    }
    
    return true;
}

bool solution(string s) 
{
    bool answer = (s.size() == 4 || s.size() == 6) && IsNumberOnly(s);
    
    return answer;
}