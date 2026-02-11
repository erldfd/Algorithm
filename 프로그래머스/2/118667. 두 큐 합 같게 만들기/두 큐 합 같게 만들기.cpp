#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
[3, 2, 7, 2] = 14
[4, 6, 5, 1] = 16
*/

int Front1, Front2;

int Pop(const vector<int>& queue, bool bIs1)
{
    int& Front = (bIs1) ? Front1 : Front2;
    
    if(Front == -1)
    {
        return -1;
    }
    
    int Element = queue[Front];
    Front++;
    
    if(Front == queue.size() - 1)
    {
        Front = -1;
    }
    
    return Element;
}

void Push(vector<int>& queue, int Element, bool bIs1)
{
    int& Front = (bIs1) ? Front1 : Front2;
    
    queue.push_back(Element);
    if(Front == -1)
    {
        Front = queue.size() - 1;
    }
}

int solution(vector<int> queue1, vector<int> queue2) 
{
    long long acc1 = 0;
    long long acc2 = 0;
    for(const int q : queue1)
    {
        acc1 += q;
    }
    
    for(const int q : queue2)
    {
        acc2 += q;
    }
    
    int answer = 0;
    const int MaxTryCount = (queue1.size() + queue2.size()) * 2;
    while(acc1 != acc2)
    {
        int Element;
        if(acc1 > acc2)
        {
            Element = Pop(queue1, true);
            Push(queue2, Element, false);
            acc1 -= Element;
            acc2 += Element;
        }
        else
        {
            Element = Pop(queue2, false);
            Push(queue1, Element, true);
            
            acc1 += Element;
            acc2 -= Element;
        }
        
        answer++;
        
        if(answer > MaxTryCount)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}