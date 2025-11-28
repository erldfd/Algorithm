#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    vector<vector<bool>> ResultTable(n, vector<bool>(n, false));
    
    for(const vector<int>& r : results)
    {
        ResultTable[r[0] - 1][r[1] - 1] = true;
    }
    
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)  
        {
            for(int j = 0; j < n; ++j)
            {
                if(ResultTable[i][k] && ResultTable[k][j])
                {
                    ResultTable[i][j] = true;
                }
            }
        }
    }
    
    int answer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        int WinCount = 0;
        for(int j = 0; j < n; ++j)
        {
            if(ResultTable[i][j] || ResultTable[j][i])
            {
                WinCount++;
            }
        }
        
        if(WinCount == n - 1)
        {
            answer++;
        }
    }
    
    return answer;
}

/*

  1 2 3 4 5
1 f t f f t
2 f f f f t
3 f t f f t
4 f t t f t
5 f f f f f


*/
    