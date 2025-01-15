
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] ==' ')
        {
            continue;
        }
        
        bool IsCapital = isupper(s[i]);
        
        s[i] += n;
        

        if(IsCapital && isupper(s[i]) == false || IsCapital == false &&  islower(s[i]) == false)
        {
            s[i] -= 26;
        }
    }

    return s;
}
