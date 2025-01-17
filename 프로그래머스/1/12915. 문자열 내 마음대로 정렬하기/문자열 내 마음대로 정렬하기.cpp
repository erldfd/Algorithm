#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
    stable_sort(strings.begin(), strings.end(), [&](const string& S1, const string S2)->bool
                {
                    if(S1[n] < S2[n])
                    {
                        return true;
                    }
                    else if(S1[n] > S2[n])
                    {
                        return false;
                    }

                    int IteratingCount = min(S1.size(), S2.size());
                    
                    for(int i = 0; i < IteratingCount; ++i)
                    {
                        if (i == n)
                        {
                            continue;
                        }
                        
                        if(S1[i] < S2[i])
                        {
                            return true;
                        }
                        else if(S1[i] > S2[i])
                        {
                            return false;
                        }
                    }
                    
                    return S1.size() < S2.size();
                });
    
    return strings;
}