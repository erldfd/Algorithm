#include <string>
#include <vector>

using namespace std;
// 우 하 좌 상
int Dx[] {0, 1, 0, -1};
int Dy[] {1, 0, -1, 0};

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int Num = 0;
    int Dir = 0;
    int X = 0;
    int Y = -1;
    
    while(Num < n * n)
    {
        int NextX = X + Dx[Dir];
        int NextY = Y + Dy[Dir];
        
        if(NextX < 0 || NextX >= n || NextY < 0 || NextY >= n || answer[NextX][NextY] != 0)
        {
            Dir = (Dir + 1) % 4;
            continue;
        }
        
        X = NextX;
        Y = NextY;
        answer[X][Y] = ++Num;
    }
    
    return answer;
}