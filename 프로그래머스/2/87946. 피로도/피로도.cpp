#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    int DungeonCount = dungeons.size();
    
    vector<int> DungeonIndexs;
    
    for(int i = 0; i < DungeonCount; ++i)
    {
        DungeonIndexs.push_back(i);
    }
    
    int answer = -1;
    
    do
    {
        int CurrentPoint = k;
        int ExploringCount = 0;
        
        for(int i = 0; i < DungeonCount; ++i)
        {
            int Index = DungeonIndexs[i];
            
            if(CurrentPoint < dungeons[Index][0])
            {
                break;
            }
            
            CurrentPoint -= dungeons[Index][1];
            ExploringCount++;
        }
        
        answer = max(answer, ExploringCount);
        
    } while(next_permutation(DungeonIndexs.begin(), DungeonIndexs.end()));
    
    return answer;
}