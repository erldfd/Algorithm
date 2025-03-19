#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int i = 1;
    int X = -1;
    int Y = 0;
    
    while(true)
    {
        bool bMovedDown = false;
        
        while(true)
        {
            if(X + 1 >= n)
            {
                break;
            }
            
            if(answer[X + 1][Y] == 0)
            {
                answer[++X][Y] = i++;
                bMovedDown = true;
            }
            else
            {
                break;
            }
        }
        
        bool bMovedRight = bMovedDown;
        
        while(bMovedRight)
        {
            if(Y + 1 >= n)
            {
                break;
            }
            
            if(answer[X][Y + 1] == 0)
            {
                answer[X][++Y] = i++;
            }
            else
            {
                break;
            }
        }
        
        bool bMovedUp = bMovedRight;
        
        while(bMovedUp)
        {
            if(X <= 0 ||Y <= 0)
            {
                break;
            }
            
            if(answer[X - 1][Y - 1] == 0)
            {
                answer[--X][--Y] = i++;
            }
            else
            {
                break;
            }
        }
        
        if(!bMovedDown && !bMovedRight && !bMovedUp)
        {
            break;
        }
    }
    
    vector<int> Answer;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(answer[i][j] == 0)
            {
                break;
            }
            
            Answer.push_back(answer[i][j]);
        }
    }
    
    return Answer;
}
    