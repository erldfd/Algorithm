#include <string>
#include <vector>

using namespace std;

// 가능한 노란색 격자의 가로, 세로길이를 리턴 
vector<pair<int, int>> CalcChancesOfYellow(int Yellow)
{
    vector<pair<int, int>> PairChance;
    
    PairChance.push_back(pair<int, int>(Yellow, 1));
    for(int i = 2; i*i <= Yellow; ++i)
    {
        if (Yellow % i == 0)
        {
            PairChance.push_back(pair<int, int>(Yellow / i, i));
        }
    }
    
    return PairChance;
}

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    vector<pair<int, int>> YellowChances = CalcChancesOfYellow(yellow);
    
    for(auto& Chance : YellowChances)
    {
        int BrownWidth = Chance.first + 2;
        int BrownHeight = Chance.second + 2;
        
        while(true)
        {
            int TotalBrownCount = BrownWidth * 2 + BrownHeight * 2 - 4;

            if (TotalBrownCount == brown)
            {
                answer.push_back(BrownWidth);
                answer.push_back(BrownHeight);
                
                return answer;
            }
            
            if(TotalBrownCount < brown)
            {
                BrownWidth += 2;
                BrownHeight += 2;
            }
            else
            {
                break;
            }
        }
    }
    
    return {-1, -1};
}
