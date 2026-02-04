#include <string>
#include <vector>

using namespace std;

vector<vector<long long>> Map;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    Map.resize(m + 1, vector<long long>(n + 1, -1));

    for(const vector<int>& puddle : puddles)
    {
        if(puddle[0] == 1)
        {
            for(int i = puddle[1]; i <= n; ++i)
            {
                Map[1][i] = 0;
            }
        }
        else if(puddle[1] == 1)
        {
            for(int i = puddle[0]; i <= m; ++i)
            {
                Map[i][1] = 0;
            }
        }
        else
        {
            Map[puddle[0]][puddle[1]] = 0;
        }
    }
    
    for(int x = 1; x <= m; ++x)
    {
        for(int y = 1; y <= n; ++y)
        {
            long long& RouteCount = Map[x][y];
            if(RouteCount == 0)
            {
                continue;
            }
            
            if(x == 1 || y == 1)
            {
                RouteCount = 1;
                continue;
            }
            
            RouteCount = (Map[x - 1][y] + Map[x][y - 1]) % 1000000007;
        }
    }
    
    return Map[m][n];
}