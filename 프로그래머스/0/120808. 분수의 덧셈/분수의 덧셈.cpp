#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) 
{
    int numer3 = (numer1 * denom2 + numer2 * denom1);
    int denom3 = (denom1 * denom2);
    
    for(int i = 2; i <= min(numer3, denom3); ++i)
    {
        while(numer3 % i == 0 && denom3 % i == 0)
        {
            numer3 /= i;
            denom3 /= i;
        }
    }
    
    return {numer3, denom3};
}