#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> Graph;
// 시간
vector<int> Memory;

int BFS(int Source, int Destination, int n)
{
    if(Memory[Source] != -2)
    {
        return Memory[Source];
    }
    
    if(Source == Destination)
    {
        Memory[Source] = 0;
        return 0;
    }
    
    vector<bool> Visited(n, false);
    Visited[Source] = true;
    
    // CurrentScore, CurrentPosition
    deque<pair<int, int>> DQ;
    DQ.push_back({0, Source});
    
    while(DQ.empty() == false)
    {
        auto [CurrentScore, CurrentPosition] = DQ.front();
        DQ.pop_front();
        
        for(int i = 0; i < Graph[CurrentPosition].size(); ++i)
        {
            int NextPosition = Graph[CurrentPosition][i];
            if(Visited[NextPosition])
            {
                continue;
            }
            
            if(Destination == NextPosition)
            {
                Memory[Source] = CurrentScore + 1;
                return CurrentScore + 1;
            }

            DQ.push_back({CurrentScore + 1, NextPosition});
            Visited[NextPosition] = true;
        }
    }
    
    for(int i = 0; i < Visited.size(); ++i)
    {
        if(Visited[i])
        {
            Memory[i] = -1;
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    Graph.resize(n, vector<int>());
    Memory.resize(n, -2);
    
    for(int i = 0; i < roads.size(); ++i)
    {
        Graph[roads[i][0] - 1].push_back(roads[i][1] - 1);
        Graph[roads[i][1] - 1].push_back(roads[i][0] - 1);
    }
    
    vector<int> answer;
    
    for(auto& source : sources)
    {
        answer.push_back(BFS(source - 1, destination - 1, n));
    }
    
    return answer;
}