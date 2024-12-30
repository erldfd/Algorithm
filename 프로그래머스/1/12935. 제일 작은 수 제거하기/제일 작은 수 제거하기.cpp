#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    auto it = std::min_element(arr.begin(), arr.end());
    
    if (it != arr.end())
    {
        arr.erase(it);
    }
    
    if (arr.size() == 0)
    {
        arr.push_back(-1);
    }
    
    return arr;
}