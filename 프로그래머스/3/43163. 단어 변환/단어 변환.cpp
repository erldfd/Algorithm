#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool CanChange(string Before, string After)
{
    int SameCount = 0;
    
    for(int i = 0; i < Before.size(); ++i)
    {
        if(Before[i] == After[i])
        {
            SameCount++;
        }
    }
    
    if(SameCount != Before.size() - 1)
    {
        return false;
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) 
{
    deque<vector<string>> BFS;
    BFS.push_back(vector<string>(1, begin));

    while(BFS.empty() == false)
    {
        auto History = BFS.back();
        string Current = History.back();
        int ChangeCount = History.size() - 1;
        
        BFS.pop_front();
        
        for(int i = 0; i < words.size(); ++i)
        {
            if(find(History.begin(), History.end(), words[i]) != History.end())
            {
                continue;
            }
            
            if(CanChange(Current, words[i]) == false)
            {
                continue;
            }

            if(words[i] == target)
            {
                return ChangeCount + 1;
            }
            
            History.push_back(words[i]);
            BFS.push_back(History);
            History.pop_back();
        }
    }
    
    return 0;
}