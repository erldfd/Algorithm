#include <queue>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int> enemy) 
{
    int answer = 0;
    
    priority_queue<int>PQ;
    
    for(int i = 0; i < enemy.size(); ++i)
    {
        PQ.push(enemy[i]);
        n-= enemy[i];
        
        while(n < 0 && k > 0)
        {
            n += PQ.top();
            PQ.pop();
            k--;
        }
        
        if(n < 0)
        {
            break;
        }
        
        answer++;
    }
    
    return answer;
}