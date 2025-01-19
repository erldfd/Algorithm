#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    vector<int> Nums;
    
    for(int i = 0; i < commands.size(); ++i)
    {
        Nums.clear(); 
        for(int j = commands[i][0] - 1; j < commands[i][1]; ++j)
        {
            Nums.push_back(array[j]);
        }
        
        sort(Nums.begin(), Nums.end());
        answer.push_back(Nums[commands[i][2] - 1]);
    }
    
    return answer;
}