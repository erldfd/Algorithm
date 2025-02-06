#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) 
{
    unordered_set<char> SkipCharSet;
    
    for(auto& SkipChar : skip)
    {
        SkipCharSet.insert(SkipChar);
    }

    for(int i =0 ; i < s.size(); ++i)
    {
        char NewChar = s[i];
        
        for(int j = 0 ; j < index; ++j)
        {
            
            NewChar++;
            
            while(SkipCharSet.find(NewChar) != SkipCharSet.end())
            {
                NewChar++;
            }
            
            if(NewChar > 'z')
            {
                NewChar -= 26;
                while(SkipCharSet.find(NewChar) != SkipCharSet.end())
                {
                    NewChar++;
                }
            }
        }

        s[i] = NewChar;
    }
    
    return s;
}