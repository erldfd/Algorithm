#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    bool IsSorted = true;
    
    deque<int> dq;
    
    for(int i = 0; i < operations.size(); ++i)
    {
        string Operation1 = operations[i].substr(0, 1);
        string Operation2 = operations[i].substr(2);
        int NumOperation = stoi(Operation2);
        
        if(Operation1 == "I")
        {
            dq.push_front(NumOperation);
            IsSorted = false;
        }
        else // if(Operation1 == D)
        {
            if(dq.empty())
            {
                continue;
            }
            
            if(IsSorted == false && dq.size() > 1)
            {
                sort(dq.begin(), dq.end());
                IsSorted = true;
            }
            
            if(NumOperation == 1)
            {
                dq.pop_back();
            }
            else // if(NumOperation == -1)
            {
                dq.pop_front();
            }
        }
    }
    
    if(dq.empty())
    {
        return {0, 0};
    }
    
    sort(dq.begin(), dq.end());
    
    return {dq.back(), dq.front()};
}