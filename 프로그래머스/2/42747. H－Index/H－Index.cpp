#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    sort(citations.begin(), citations.end());
    
    int citationsCount = citations.size();
    
    int HIndex = 0;
    
    for(int i = 0; i < citationsCount; ++i)
    {
        int citation = citations[i];
        
        while(HIndex + 1 <= citation && HIndex + 1 <= citationsCount - i &&
             HIndex + 1 >= i && HIndex + 1 <= citations.back())
        {
            HIndex++;
        }
    }
    
    return HIndex;
}