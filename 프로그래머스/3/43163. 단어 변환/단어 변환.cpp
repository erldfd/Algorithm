#include <string>
#include <vector>
#include <deque>
#include <unordered_set>

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
    unordered_set<string> Visited;
    deque<pair<string, int>> BFS;
    BFS.push_back({begin, 0});
    
    while(BFS.empty() == false)
    {
        auto [CurrentWord, ChangeCount] = BFS.back();
        BFS.pop_front();
        
        for(int i = 0; i < words.size(); ++i)
        {
            if(Visited.find(words[i]) != Visited.end())
            {
                continue;
            }
            
            if(CanChange(CurrentWord, words[i]) == false)
            {
                continue;
            }

            if(words[i] == target)
            {
                return ChangeCount + 1;
            }
            
            Visited.insert(words[i]);
            BFS.push_back({words[i], ChangeCount + 1});
        }
    }
    
    return 0;
}