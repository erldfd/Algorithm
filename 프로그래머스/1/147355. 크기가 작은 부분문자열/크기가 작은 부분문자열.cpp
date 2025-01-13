#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    
    long long NumP = stoll(p);
    int PSize = p.size();
    int TSize = t.size();
    
    for(int i = 0; i < TSize; ++i)
    {
        string PartString = "";
        
        for(int j = 0; j < PSize && (i + j < TSize); ++j)
        {
            
            PartString += t[i + j];
        }
        
        if (PartString.size() == PSize && stoll(PartString) <= NumP)
        {
            answer++;
        }
    }
    
    return answer;
}