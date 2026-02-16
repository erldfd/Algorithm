#include <string>
#include <vector>

using namespace std;

float Get(const vector<vector<int>>& Dots)
{
    return float(Dots[0][0] - Dots[1][0]) / (Dots[0][1] - Dots[1][1]);
}

int solution(vector<vector<int>> dots) 
{
    vector<bool> Visited(1 << 4, false);
    
    vector<vector<int>> Dots1;
    vector<vector<int>> Dots2;

    for(int i = 0; i < (1 << 4); ++i)
    {
        Dots1.clear();
        Dots2.clear();
        
        int bit = 0;
        int Count = 0;
        for(int j = 0; j < 4; ++j)
        {
            if((1 << j) & i)
            {
                bit |= (1 << j);
                Count++;
            }
            
            if(Count == 2)
            {
                break;
            }
        }
        
        if(Visited[bit] == false && Count == 2)
        {
            Visited[bit] = true;
            
            for(int k = 0; k < 4; ++k)
            {
                if(1 << k & bit)
                {
                    Dots1.push_back(dots[k]);
                }
                else
                {
                    Dots2.push_back(dots[k]);
                }
            }
            
            if(Get(Dots1) == Get(Dots2))
            {
                return 1;
            }
        }
    }
    
    return 0;
}