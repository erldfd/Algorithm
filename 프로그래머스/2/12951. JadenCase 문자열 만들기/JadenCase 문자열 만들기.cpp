#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    s[0] = toupper(s[0]);
    
    for(int i = 1; i < s.size(); ++i)
    {
        s[i] = (s[i - 1] == ' ') ? toupper(s[i]) : tolower(s[i]);
    }
    
    return s;
}