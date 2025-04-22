#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<string> Grids;

// 상 하 좌 우 0 1 2 3
vector<int> dx {-1, 1, 0, 0};
vector<int> dy {0, 0, -1, 1};

vector<int> MeetLeft {2, 3, 1, 0};
vector<int> MeetRight {3, 2, 0, 1};

int Visited[500][500][4] = {false};

// NextX, NextY, NextDirection
tuple<int, int, int> Move(int CurrentX, int CurrentY, int Direction)
{
    int NextX = CurrentX + dx[Direction];
    NextX = (NextX < 0) ? NextX + Grids.size() : NextX % Grids.size();
    
    int NextY = CurrentY + dy[Direction];
    NextY = (NextY < 0) ? NextY + Grids[0].size() : NextY % Grids[0].size();
    
    char NextGrid = Grids[NextX][NextY];
    
    int NextDirection = 0;
    
    if(NextGrid == 'S')
    {
        NextDirection = Direction;
    }
    else if(NextGrid == 'L')
    {
        NextDirection = MeetLeft[Direction];
    }
    else // if(NextGrid == 'R')
    {
        NextDirection = MeetRight[Direction];
    }
    
    return {NextX, NextY, NextDirection};
}

vector<int> solution(vector<string> grid) 
{
    Grids = grid;
    
    vector<int> answer;
    
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            for(int direction = 0; direction < 4; ++direction)
            {
                if(Visited[i][j][direction])
                {
                    continue;
                }
                
                int StartX = i;
                int StartY = j;
                int StartDirection = direction;
                int MoveCount = 0;
                
                while(Visited[i][j][direction] == false)
                {
                    Visited[i][j][direction] = true;
                    MoveCount++;
                    
                    auto [NextX, NextY, NextDirection] = Move(i, j, direction);
                    
                    i = NextX;
                    j = NextY;
                    direction = NextDirection;
                }
                
                if(StartX == i && StartY == j && StartDirection == direction)
                {
                    answer.push_back(MoveCount);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}