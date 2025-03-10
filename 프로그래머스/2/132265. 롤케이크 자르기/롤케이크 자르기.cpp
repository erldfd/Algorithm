#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) 
{
    // 몇 번 인덱스 뒤에서 잘랐을 때 왼쪽의 토핑 타입 개수
    vector<int> ToppingCounts;
    unordered_set<int> ToppingTypeSet;
    
    // 오른쪽
    vector<int> ToppingCountsRight;
    unordered_set<int> ToppingTypeSetRight;
    
    for(int i = 0; i < topping.size() - 1; ++i)
    {
        ToppingTypeSet.insert(topping[i]);
        ToppingCounts.push_back(ToppingTypeSet.size());
        
        ToppingTypeSetRight.insert(topping[topping.size() - 1 - i]);
        ToppingCountsRight.push_back(ToppingTypeSetRight.size());
    }

    int answer = 0;
    
    for(int i = 0; i< ToppingCounts.size(); ++i)
    {
        if(ToppingCounts[i] == ToppingCountsRight[ToppingCounts.size() - 1 - i])
        {
            answer++;
        }
    }
    
    return answer;
}