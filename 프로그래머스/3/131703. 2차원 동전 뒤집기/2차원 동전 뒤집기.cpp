#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) 
{
    int SizeX = beginning.size();
    int SizeY = beginning[0].size();
    
    int answer = 101;
    
    for(int i = 0; i < (1 << SizeX); ++i)
    {
        vector<vector<int>> Initial = beginning;
        int FlipCount = 0;
        
        for(int j = 0; j < SizeX; ++j)
        {
            if((i & (1 << j)) == false)
            {
                continue;
            }
            
            FlipCount++;
            for(int k = 0; k < SizeY; ++k)
            {
                Initial[j][k] ^= 1;
            }
        }
        
        for(int j = 0; j < SizeY; ++j)
        {
            if(Initial[0][j] == target[0][j])
            {
                continue;
            }
            
            FlipCount++;
            for(int k = 0; k < SizeX; ++k)
            {
                Initial[k][j] ^= 1;
            }
        }
        
        bool IsSame = true;
        for(int a = 0; a < SizeX; ++a)
        {
            for(int b = 0; b < SizeY; ++b)
            {
                if(Initial[a][b] != target[a][b])
                {
                    IsSame = false;
                    break;
                }
            }
        }
        
        if(IsSame)
        {
            answer = min(answer, FlipCount);
        }
    }
    
    return (answer == 101) ? -1 : answer;
}