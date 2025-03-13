#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 1;
    
    // truck Index, RemainingTime
    deque<pair<int, int>> TrucksOnBridge;
    TrucksOnBridge.push_front(make_pair(0, bridge_length));
    int CurrentTotalWeight = truck_weights[0];
    int NextTruckIndex = 1;
    
    while(NextTruckIndex < truck_weights.size() || TrucksOnBridge.empty() == false)
    {
        for(auto& truck : TrucksOnBridge)
        {
            truck.second--;
        }

        if(TrucksOnBridge.back().second == 0)
        {
            CurrentTotalWeight -= truck_weights[TrucksOnBridge.back().first];
            TrucksOnBridge.pop_back();
        }
        
        answer++;
        
        int RemainingWeight = weight - CurrentTotalWeight;
        
        if(TrucksOnBridge.size() < bridge_length && NextTruckIndex < truck_weights.size() &&
          RemainingWeight >= truck_weights[NextTruckIndex])
        {
            CurrentTotalWeight += truck_weights[NextTruckIndex];
            TrucksOnBridge.push_front(make_pair(NextTruckIndex, bridge_length));
            NextTruckIndex++;
        }
    }
    
    return answer;
}