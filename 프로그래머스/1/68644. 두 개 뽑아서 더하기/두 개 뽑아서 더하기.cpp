#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    unordered_set<int> sumNumberSet;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i =  0; i < numbers.size(); ++i)
    {
        for(int j = numbers.size() - 1 ; j > i; --j)
        {
            sumNumberSet.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer;
    
    for(auto& num : sumNumberSet)
    {
        answer.push_back(num);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}