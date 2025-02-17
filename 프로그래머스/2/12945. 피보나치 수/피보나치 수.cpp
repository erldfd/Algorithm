#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    vector<long long> F;
    F.reserve(100001);
    F.push_back(0);
    F.push_back(1);
    
    for(int i = 2; i <= n; ++i)
    {
        F.push_back((F[i - 2] + F[i - 1]) % 1234567);
    }
    
    return F[n];
}