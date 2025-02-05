#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CheckInputCount(vector<string>& keymap, const char& t)
{
    int IteratingCount = keymap[0].size();

    for(int i, j = 0 ; j < IteratingCount; ++j)
    {
        for(i = 0; i < keymap.size(); ++i)
        {
            IteratingCount = max(IteratingCount, (int)keymap[i].size());
            
            if(j >= keymap[i].size())
            {
                continue;
            }
            
            char key = keymap[i][j];

            if(key == t)
            {
                return j + 1;
            }
        }
    }

    return 0;
}

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    
    for(const string& target : targets)
    {
        int InputCounts = 0;
        
        for(const char& t : target)
        {
            int Count = CheckInputCount(keymap, t);
            
            if(Count <= 0)
            {
                InputCounts = -1;
                break;
            }
            
            InputCounts += Count;
        }
        
        answer.push_back(InputCounts);
    }
    
    return answer;
}