#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int ProgressIndex = 0;
    
    while(ProgressIndex < speeds.size())
    {
        if(speeds[ProgressIndex] <= 0)
        {
            break;
        }

        int DistributeCount = 0;
        
        for(int i = ProgressIndex; i < speeds.size(); ++i)
        {
            progresses[i] += speeds[i];
            
            if(progresses[i] >= 100 && ProgressIndex == i)
            {
                DistributeCount++;
                ProgressIndex++;
            }
        }
        
        if(DistributeCount > 0)
        {
            answer.push_back(DistributeCount);
        }
    }
    
    return answer;
}