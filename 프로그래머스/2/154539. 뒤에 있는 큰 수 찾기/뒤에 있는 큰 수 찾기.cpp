#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), -1);
    vector<int> NotChoosedIndexs;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        while(NotChoosedIndexs.size() > 0 && numbers[NotChoosedIndexs.back()] < numbers[i])
        {
            answer[NotChoosedIndexs.back()] = numbers[i];
            NotChoosedIndexs.pop_back();
        }
        
        NotChoosedIndexs.push_back(i);
    }
    
    return answer;
}