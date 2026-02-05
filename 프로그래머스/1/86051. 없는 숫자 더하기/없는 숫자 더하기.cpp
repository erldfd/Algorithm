#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> numbers) 
{
    unordered_set<int> Set(numbers.begin(), numbers.end());
    int answer = 45;

    for(int s : Set)
    {
        answer -= s;
    }
    
    return answer;
}