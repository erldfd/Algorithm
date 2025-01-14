#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int MaxWidth = 0;
    int MaxHeight = 0;
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        int Bigger = max(sizes[i][0], sizes[i][1]);
        int Smaller = min(sizes[i][0], sizes[i][1]);
        
        MaxWidth = max(Bigger, MaxWidth);
        MaxHeight = max(Smaller, MaxHeight);
    }
    
    int answer = MaxWidth * MaxHeight;
    return answer;
}