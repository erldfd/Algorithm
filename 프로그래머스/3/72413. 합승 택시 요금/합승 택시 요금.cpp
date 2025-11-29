#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    const int MAX = 2000000000;
    vector<vector<int>> Table(n + 1, vector<int>(n + 1, MAX));
    
    for(const vector<int>& fare : fares)
    {
        Table[fare[0]][fare[1]] = fare[2];
        Table[fare[1]][fare[0]] = fare[2];
    }
    
    for(int i = 0; i <= n; ++i)
    {
        Table[i][i] = 0;
    }
    
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(Table[i][k] == MAX)
            {
                continue;
            }
            
            for(int j = 1; j <= n; ++j)
            {
                if(Table[k][j] == MAX)
                {
                    continue;
                }
                
                Table[i][j] = min(Table[i][j], Table[i][k] + Table[k][j]);
            }
        }
    }

    int answer = MAX;
    for(int k = 1; k <= n; ++k)
    {
        int SK = Table[s][k];
        if(SK == MAX)
        {
            continue;
        }
        
        int KA = Table[k][a];
        if(KA == MAX)
        {
            continue;
        }
        
        int KB = Table[k][b];
        if(KB == MAX)
        {
            continue;
        }
        
        answer = min(answer, SK + KA + KB);
    }

    return answer;
}