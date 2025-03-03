#include <string>
#include <vector>
#include <deque>
#include <queue>

struct Process
{
    Process(int NewPriority, int NewId)
    {
        Priority = NewPriority;
        Id = NewId;
    }
    
    int Priority;
    int Id;

};

struct Compare
{
    bool operator()(const Process& a, const Process& b)
    {
        return a.Priority < b.Priority;
    }
};

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int WatchingProcessId = location;
    deque<Process> WaitingQueue;
    priority_queue<Process, vector<Process>, Compare> FirstPriority;
    
    for(int i = 0; i < priorities.size(); ++i)
    {
        Process NewProcess = Process(priorities[i], i);
        
        WaitingQueue.push_back(NewProcess);
        FirstPriority.push(NewProcess);
    }

    int Order = 1;

    while(WaitingQueue.size() > 0)
    {
        if(WaitingQueue[0].Priority >= FirstPriority.top().Priority)
        {
            if(WaitingQueue[0].Id == WatchingProcessId)
            {
                return Order;
            }
            
            WaitingQueue.pop_front();
            FirstPriority.pop();
            Order++;
        }
        else
        {
            WaitingQueue.push_back(WaitingQueue.front());
            WaitingQueue.pop_front();
        }
    }
    
    return -1;
}