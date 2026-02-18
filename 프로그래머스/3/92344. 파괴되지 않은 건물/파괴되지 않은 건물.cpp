#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    const int n = board.size();
    const int m = board[0].size();
    vector<vector<int>> Diff(n, vector<int>(m, 0));
    
    for(const vector<int>& s : skill)
    {
        int Type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];
        
        int ActualDegree = (Type == 1) ? -degree : degree;
        Diff[r1][c1] += ActualDegree;
        if(c2 + 1 < m)
        {
            Diff[r1][c2 + 1] -= ActualDegree;
        }
        
        if(r2 + 1 < n)
        {
            Diff[r2 + 1][c1] -= ActualDegree;
        }
        
        if(c2 + 1 < m && r2 + 1 < n)
        {
            Diff[r2 + 1][c2 + 1] += ActualDegree;
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            Diff[i][j] += Diff[i][j - 1];
        }
    }
    
    for(int i = 0; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            Diff[j][i] += Diff[j - 1][i];
        }
    }
    
    int answer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] + Diff[i][j] > 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}