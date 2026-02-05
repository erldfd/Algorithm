#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;
//  d l r u

int X, Y, R, C, N, M, K;

// u d l r
int Dx[] {1, -1, 0, 0};
int Dy[] {0, 0, -1, 1};
char Direction[] {'d', 'u', 'l', 'r'};

struct Compare
{
    bool operator()(const tuple<int, int, string>& A, const tuple<int, int, string>& B)
    {
        auto [Ax, Ay, As] = A;
        auto [Bx, By, Bs] = B;
        return As > Bs;
    }
};

bool CanReach(int CurrX, int CurrY, int Step)
{
    int RemainDistance = abs(CurrX - R) + abs(CurrY - C);
    int MoveableCount = K - Step;
    return (MoveableCount) >= (RemainDistance) && MoveableCount % 2 == RemainDistance % 2;
}

string BFS()
{
    // x, y, Route
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, Compare> Queue;
    Queue.push({X, Y, ""});
    
    while(Queue.empty() == false)
    {
        auto [CurrX, CurrY, CurrRoute] = Queue.top();
        Queue.pop();
        
        if(CanReach(CurrX, CurrY, CurrRoute.size()) == false)
        {
            continue;
        }

        if(CurrRoute.size() == K && CurrX == R && CurrY == C)
        {
             return CurrRoute;
        }
        
        for(int i = 0; i < 4; ++i)
        {
            int NextX = CurrX + Dx[i];
            int NextY = CurrY + Dy[i];
            
            if(NextX < 1 || NextY < 1 || NextX > N || NextY > M)
            {
                continue;
            }
            
            if(CanReach(NextX, NextY, CurrRoute.size() + 1) == false)
            {
                continue;
            }
            
            Queue.push({NextX, NextY, CurrRoute + Direction[i]});
        }
    }
    
    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    N = n;
    M = m;
    X = x;
    Y = y;
    R = r;
    C = c;
    K = k;

    return BFS();
}