#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = 0;
    
    deque<int> deque1;
    deque<int> deque2;
    
    long long Sum1 = 0;
    long long Sum2 = 0;
    
    for(int i = 0; i < queue1.size(); ++i)
    {
        deque1.push_back(queue1[i]);
        Sum1 += queue1[i];
    }
    
    for(int i = 0; i < queue2.size(); ++i)
    {
        deque2.push_back(queue2[i]);
        Sum2 += queue2[i];
    }
    
    long long AimValue = (Sum1 + Sum2) / 2;
    
    while(AimValue != Sum1)
    {
        if(Sum1 > AimValue)
        {
            Sum1 -= deque1.front();
            Sum2 += deque1.front();
            deque2.push_back(deque1.front());
            deque1.pop_front();
        }
        else
        {
            Sum1 += deque2.front();
            Sum2 -= deque2.front();
            deque1.push_back(deque2.front());
            deque2.pop_front();
        }
        
        answer++;
        
        if(answer > (queue1.size() + queue2.size()) * 2)   
        {
            return -1;
        }
    }
    
    return answer;
}