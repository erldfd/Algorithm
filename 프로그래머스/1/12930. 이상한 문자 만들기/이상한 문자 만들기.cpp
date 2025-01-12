#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    int gap = (int)('a' - 'A');

    for(int i = 0, j = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            j = 0;
            continue;
        }
        
        if (j % 2 == 0 && s[i] >= 'a')
        {
            s[i] -= gap;
        }
        else if(j % 2 != 0 && s[i] < 'a')
        {
            s[i] += gap;
        }
        
        j++;
    }
    
    return s;
}