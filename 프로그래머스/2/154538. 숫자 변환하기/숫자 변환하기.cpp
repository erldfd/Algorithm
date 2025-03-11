#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int x, int y, int n) 
{
    deque<pair<int, int>> BFSQueue;
    BFSQueue.push_front(make_pair(y, 0));
    
    while(BFSQueue.size() > 0)
    {
        int CurrentValue = BFSQueue.back().first;
        int Depth = BFSQueue.back().second;
        
        if(CurrentValue == x)
        {
            return Depth;
        }
        
        BFSQueue.pop_back();
        
        if(CurrentValue % 3 == 0)
        {
            BFSQueue.push_front(make_pair(CurrentValue / 3, Depth + 1));
        }
        
        if(CurrentValue % 2 == 0)
        {
            BFSQueue.push_front(make_pair(CurrentValue / 2, Depth + 1));
        }
        
        if(CurrentValue > n)
        {
            BFSQueue.push_front(make_pair(CurrentValue - n, Depth + 1));
        }
    }
    
    
    return -1;
}