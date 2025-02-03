#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    vector<int> GymSuitCountList = vector<int>(n, 1);
    int answer = 0;
    
    for(const auto& l : lost)
    {
        GymSuitCountList[l - 1]--;
    }
    
    for(const auto& r : reserve)
    {
        GymSuitCountList[r - 1]++;
    }
    
    for(int i = 0; i < GymSuitCountList.size(); ++i)
    {
        if(i == 0 && GymSuitCountList[0] == 0 && GymSuitCountList[1] == 2)
        {
            GymSuitCountList[0]++;
            GymSuitCountList[1]--;
        }
        else if(i == GymSuitCountList.size() - 1 && GymSuitCountList[i] == 0 &&
               GymSuitCountList[i - 1] == 2)
        {
            GymSuitCountList[i]++;
            GymSuitCountList[i - 1]--;
        }
        else if(GymSuitCountList[i] == 0)
        {
            if(GymSuitCountList[i - 1] == 2)
            {
                GymSuitCountList[i - 1]--;
                GymSuitCountList[i]++;
            }
            else if(GymSuitCountList[i + 1] == 2)
            {
                GymSuitCountList[i + 1]--;
                GymSuitCountList[i]++;
            }
        }
        
        if(GymSuitCountList[i] > 0)
        {
            answer++;
        }
    }
    
    return answer;
}