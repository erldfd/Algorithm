#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Graph;
// 0 -> 켰다, 1 -> 껐다
vector<vector<int>> DP;

vector<int> Parent;

void DFS(int Current, int Parent)
{
    DP[Current][0] = 1;
    DP[Current][1] = 0;
    
    const vector<int>& Children = Graph[Current];
    for(int Child : Children)
    {
        if(Child == Parent)
        {
            continue;
        }
        
        DFS(Child, Current);
        
        DP[Current][0] += min(DP[Child][0], DP[Child][1]);
        DP[Current][1] += DP[Child][0];
    }
}

int solution(int n, vector<vector<int>> lighthouse) 
{
    Graph.resize(n, vector<int>());
    DP.resize(n, vector<int>(2, 0));
    
    for(const vector<int>& l : lighthouse)
    {
        Graph[l[0] - 1].push_back(l[1] - 1);
        Graph[l[1] - 1].push_back(l[0] - 1);
    }
    
    DFS(0, -1);

    return min(DP[0][0], DP[0][1]);
}