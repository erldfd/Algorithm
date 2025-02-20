#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int x, int y) 
{ 
    return x % y == 0 ? y : GCD(y, x % y); 
}

int LCM(int x, int y) 
{ 
    return x * y / GCD(x, y); 
}

int solution(vector<int> arr) 
{
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++)
    {
        answer = LCM(answer, arr[i]);
    }
        
    return answer;
}