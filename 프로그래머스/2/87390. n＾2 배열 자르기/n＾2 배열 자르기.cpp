#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    
    vector<int> answer;
    
    for(long long i = left; i <= right; ++i)
    {
        int X = i / n + 1;
        int Y = i % n + 1;
        
        answer.push_back(max(X, Y));
    }
    
    return answer;
}