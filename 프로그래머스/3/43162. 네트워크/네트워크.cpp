#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    vector<bool> Visited(n, false);
    
    int answer = 0;
    
    for(int x = 0; x < n; ++x)
    {
        if(Visited[x])
        {
            continue;
        }
        
        answer++;
        
        vector<int> DFS;
        
        DFS.push_back(x);
        Visited[x] = true;

        while(DFS.empty() == false)
        {
            int Current = DFS.back();
            DFS.pop_back();

            for(int i = 0; i < computers[Current].size(); ++i)
            {
                bool IsConnected = (bool)computers[Current][i];
                
                if(IsConnected == false)
                {
                    continue;
                }
                
                if(Visited[i])
                {
                    continue;
                }

                Visited[i] = true;
                DFS.push_back(i);
            }
        }
    }
    
    return answer;
}