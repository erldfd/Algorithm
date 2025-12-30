#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MINIMUM = -30001;

int solution(vector<vector<int>> routes) 
{
    sort(routes.begin(), routes.end(), [](const vector<int>& A, const vector<int>& B)
         {
             return A[0] < B[0];
         });
    
    int Min = MINIMUM;
    int Max = MINIMUM;
    
    int answer = 0;
    
    for(const vector<int>& r : routes)
    {
        if(Min <= r[0] && Max >= r[0])
        {
            Min = max(Min, r[0]);
            Max = min(Max, r[1]);
        }
        else
        {
            Min = r[0];
            Max = r[1];
            answer++;
        }
    }
    
    return answer;
}