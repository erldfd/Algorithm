#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    
    for(auto& number : numbers)
    {
        long long BitNum = 1;
        
        while((number & BitNum) != 0)
        {
            BitNum <<= 1;
        }
        
        answer.push_back(number + BitNum - (BitNum >> 1));
    }
    
    return answer;
}