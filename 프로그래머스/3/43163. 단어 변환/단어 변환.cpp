#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

bool CanChange(string& From, string& To)
{
    int Count = 0;
    for(int i = 0; i < From.size(); ++i)
    {
        if(From[i] == To[i])
        {
            Count++;
        }
    }

    return (Count == From.size() - 1);
}

int FindShortestCount(const string& begin, const string& target, vector<string>& words)
{
    int ShortestCount = 999999;
    
    vector<tuple<string, int,unordered_set<string>>> DFS;
    unordered_set<string> Visited;
    Visited.insert(begin);
    DFS.push_back({begin, 0, Visited});
    
    while(DFS.empty() == false)
    {
        auto [Current, TransformCount, CurrentVisited] = DFS.back();
        DFS.pop_back();
        
        if(Current == target)
        {
            ShortestCount = min(ShortestCount, TransformCount);
            continue;
        }
        
        for(int i = 0; i < words.size(); ++i)
        {
            if(CurrentVisited.find(words[i]) != CurrentVisited.end())
            {
                continue;
            }
            
            bool bCanChange = CanChange(Current, words[i]);
            
            if(bCanChange)
            {
                auto NextVisited = CurrentVisited;
                NextVisited.insert(words[i]);
                DFS.push_back({words[i], TransformCount + 1, NextVisited});
            }
        }
    }
    
    return (ShortestCount == 999999) ? 0 : ShortestCount;
}

int solution(string begin, string target, vector<string> words) 
{
    return FindShortestCount(begin, target, words);
}