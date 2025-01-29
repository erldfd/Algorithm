#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 1;
    int PaintingCount = 1;
    int PrevSection = section[0];
    int RemainRollerLength = m;
    
    for(int i = 1; i < section.size(); ++i)
    {
        int CurrentSection = section[i];
        RemainRollerLength -= CurrentSection - PrevSection;
        
        if(RemainRollerLength <= 0)
        {
            RemainRollerLength = m;
            answer++;
        }
        
        PrevSection = CurrentSection;
    }
    
    return answer;
}