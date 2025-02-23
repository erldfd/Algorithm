#include <string>
#include <vector>

using namespace std;

bool IsCorrect(const string& str)
{
    string temp = "";
    
    for(auto& c : str)
    {
        if(c == '[' || c == '(' || c == '{')
        {
            temp +=c;
        }
        else if(c == ']' && temp.back() == '['||
               c == ')' && temp.back() == '(' ||
               c =='}' && temp.back() == '{')
        {
            temp.pop_back();
        }
        else
        {
            return false;
        }
    }
    
    return (temp.size() == 0);
}

int solution(string s) 
{
    int answer = 0;
    
    for(int i = 0 ; i < s.size(); ++i)
    {
        if(IsCorrect(s))
        {
            answer++;
        }
        
        s.insert(s.begin(), s.back());
        s.pop_back();
    }
    
    return answer;
}