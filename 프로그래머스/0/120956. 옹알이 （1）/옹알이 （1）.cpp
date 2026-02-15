#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> Pronunciations
{
    "aya",
    "ye",
    "woo",
    "ma"
};

bool CanPronounce(const string& s)
{
    string Temp = "";
    for(char c : s)
    {
        Temp += c;
        if(Pronunciations.find(Temp) == Pronunciations.end())
        {
            continue;
        }
        
        Temp = "";
    }
    
    return (Temp.size() == 0);
}

int solution(vector<string> babbling) 
{
    int answer = 0;
    
    for(const string& b : babbling)
    {
        if(CanPronounce(b))
        {
            answer++;
        }
    }
    
    return answer;
}