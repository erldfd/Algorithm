#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    int i = n - 1;
    int j = n - 1;
    long long answer = 0;
    
    while(j >= 0 || i >= 0)
    {
        while(i >= 0 && deliveries[i] == 0)
        {
            i--;
        }
        
        int DeliveryDistance = (i + 1) * 2;
        
        while(j >= 0 && pickups[j] == 0)
        {
            j--;
        }
        
        int PickupDistance = (j + 1) * 2;
        
        answer += max(DeliveryDistance, PickupDistance);
        
        int DeliveryCount = cap;
        while(true)
        {
            if(i < 0)
            {
                break;
            }
            
            int& CurrentDelivery = deliveries[i];
            if(CurrentDelivery > DeliveryCount)
            {
                CurrentDelivery -= DeliveryCount;
                DeliveryCount = 0;
                break;
            }
            else
            {
                DeliveryCount -= CurrentDelivery;
                CurrentDelivery = 0;
                i--;
            }
        }
        
        int PickupCount = cap;
        while(true)
        {
            if(j < 0)
            {
                break;
            }
            
            int& CurrentPickup = pickups[j];
            if(CurrentPickup > PickupCount)
            {
                CurrentPickup -= PickupCount;
                PickupCount = 0;
                break;
            }
            else
            {
                PickupCount -= CurrentPickup;
                CurrentPickup = 0;
                j--;
            }
        }
    }
    
    return answer;
}