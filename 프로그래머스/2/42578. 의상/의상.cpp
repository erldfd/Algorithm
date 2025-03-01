#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    // 종류, 이름들
    unordered_map<string, vector<string>> ClothesMap;
    
    for(auto& c : clothes)
    {
        ClothesMap[c.back()].push_back(c[0]);
    }
    
    int answer = 1;
    
    for(auto& Clothes : ClothesMap)
    {
        answer *= Clothes.second.size() + 1;
    }

    return answer - 1;
}