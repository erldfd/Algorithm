#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> CharPositionMap;

vector<int> solution(string s) 
{
    vector<int> answer;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if (CharPositionMap.find(s[i]) != CharPositionMap.end())
        {
            answer.push_back(i - CharPositionMap[s[i]]);
        }
        else
        {
            answer.push_back(-1);
        }
        
        CharPositionMap[s[i]] = i;
    }

    return answer;
}