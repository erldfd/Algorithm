#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    
    for(auto& number : numbers)
    {
        long long BitNum = (~number & -~number);
        
        answer.push_back(number + BitNum - (BitNum >> 1));
    }
    
    return answer;
}