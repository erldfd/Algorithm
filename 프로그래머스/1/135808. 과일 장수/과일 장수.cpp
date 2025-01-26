#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    
    sort(score.rbegin(), score.rend());
    
    int Smaller = 9;
    
    int count = score.size() - score.size() % m;
    
    for(int i = 0; i < count; ++i)
    {
        Smaller = min(Smaller, score[i]);
        
        if(i % m == m - 1)
        {
            answer += Smaller * m;
        }
    }
    
    return answer;
}