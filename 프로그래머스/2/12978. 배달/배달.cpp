#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) 
{
    vector<vector<int>> Graph(N, vector<int>(N, 2000000000));
    
    for(int i = 0 ; i < road.size(); ++i)
    {
        Graph[road[i][0] - 1][road[i][1] - 1] = min(Graph[road[i][0] - 1][road[i][1] - 1], road[i][2]);
        Graph[road[i][1] - 1][road[i][0] - 1] = min(Graph[road[i][1] - 1][road[i][0] - 1], road[i][2]);
    }
    
    vector<int> NodeMinScore(N, 2100000000);
    
    
    deque<pair<int, int>>BFS;
    vector<bool> Visited(N, false);
    int answer = 1;

    BFS.push_front({0, 0});
    Visited[0] = true;
    NodeMinScore[0] = 0;
    
    while(BFS.empty() == false)
    {
        auto [CurrentNode, CurrentScore] = BFS.back();
        
        BFS.pop_back();
        
        for(int i = 0; i < N; ++i)
        {
            int NextNode = i;
            int NextScore = Graph[CurrentNode][i] + CurrentScore;
            
            if(NextScore > K)
            {
                continue;
            }
            
            if(NodeMinScore[i] <= NextScore)
            {
                continue;
            }

            if(Visited[NextNode] == false)
            {
                answer++;
                Visited[NextNode] = true;
            }
            NodeMinScore[i] = NextScore;
            BFS.push_front({NextNode, NextScore});
        }
    }
    
    return answer;
}