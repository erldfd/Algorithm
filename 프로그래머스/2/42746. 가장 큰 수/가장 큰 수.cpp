#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) 
{
    vector<string> numStrs;
    for(auto& number : numbers)
    {
        numStrs.push_back(to_string(number));
    }
    
    sort(numStrs.begin(), numStrs.end(), [](const string& a, const string& b)
         {
            return (a + b > b + a);
         });
    
    string answer = numStrs[0];
    
    if(answer == "0")
    {
        return answer;
    }

    for(int i =1; i < numStrs.size(); ++i)
    {
        answer += numStrs[i];
    }

    return answer;
}