#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    int Card1Index = 0;
    int Card2Index = 0;
    
    for(int GoalIndex = 0; GoalIndex < goal.size(); ++GoalIndex)
    {
        if(cards1[Card1Index] == goal[GoalIndex])
        {
            Card1Index++;
        }
        else if(cards2[Card2Index] == goal[GoalIndex])
        {
            Card2Index++;
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}