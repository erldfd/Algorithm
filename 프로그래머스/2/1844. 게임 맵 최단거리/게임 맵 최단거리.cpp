#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int SizeX = maps.size();
    int SizeY = maps[0].size();
    
    if(SizeX == 1 && SizeY == 1)
    {
        return 1;
    }
    
    vector<vector<bool>> Visited(SizeX, vector<bool>(SizeY, false));
    vector<vector<int>> Distances(SizeX, vector<int>(SizeY, 0));
    
    deque<pair<int, int>> BFS;
    BFS.push_back({0, 0});
    Visited[0][0] = true;
    Distances[0][0]++;
    
    while(BFS.empty() == false)
    {
        auto [CurrentX, CurrentY] = BFS.front();
        BFS.pop_front();
        
        for(int i = 0; i < 4; ++i)
        {
            int NextX = CurrentX + dx[i];
            int NextY = CurrentY + dy[i];
            
            if(NextX < 0 || NextY < 0 ||
              NextX >= SizeX || NextY >= SizeY)
            {
                continue;
            }
            
            if(Visited[NextX][NextY])
            {
                continue;
            }
            
            bool IsMoveable = (bool)maps[NextX][NextY];
            
            if(IsMoveable == false)
            {
                continue;
            }
            
            if(NextX == SizeX - 1 && NextY == SizeY - 1)
            {
                return Distances[CurrentX][CurrentY] + 1;
            }
            
            Visited[NextX][NextY] = true;
            Distances[NextX][NextY] = Distances[CurrentX][CurrentY] + 1;
            BFS.push_back({NextX, NextY});
        }
    }
    
    int answer = -1;
    return answer;
}