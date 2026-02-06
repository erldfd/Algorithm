#include <string>
#include <vector>

using namespace std;

/*

00100
01110
11111
01110
00100

길찾기를 사람마다 계속해서 사람을 만나면 실패?

*/

int Dx[] {-1, 1, 0, 0};
int Dy[] {0, 0, -1, 1};

vector<vector<bool>> Visited;

bool IsInRange(int X, int Y, int TargetX, int TargetY)
{
    return (abs(X - TargetX) + abs(Y - TargetY) <= 2);
}

bool IsGood(int CenterX, int CenterY, int X, int Y, const vector<string>& Place)
{
    for(int i = 0; i < 4; ++i)
    {
        int NextX = X + Dx[i];
        int NextY = Y + Dy[i];
        
        if(NextX < 0 || NextX > 4 || NextY < 0 || NextY > 4)
        {
            continue;
        }
        
        if(NextX == CenterX && NextY == CenterY)
        {
            continue;
        }
        
        if(IsInRange(CenterX, CenterY, NextX, NextY) == false)
        {
            continue;
        }
        
        if(Place[NextX][NextY] == 'X')
        {
            continue;
        }
        
        if(Place[NextX][NextY] == 'P')
        {
            return false;
        }
        
        if(Visited[NextX][NextY])
        {
            continue;
        }
        
        Visited[NextX][NextY] = true;
        if(IsGood(CenterX, CenterY, NextX, NextY, Place) == false)
        {
            return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer(places.size(), 1);
    
    for(int i = 0; i < places.size(); ++i)
    {
        Visited.clear();
        Visited.resize(5, vector<bool>(5, false));
        
        for(int x = 0; x < 5; ++x)
        {
            bool bFinished = false;
            for(int y = 0; y < 5; ++y)
            {
                if(places[i][x][y] == 'P' && IsGood(x, y, x, y, places[i]) == false)
                {
                    answer[i] = 0;
                    bFinished = true;
                    break;
                }
            }
            
            if(bFinished)
            {
                break;
            }
        }
    }
    
    return answer;
}