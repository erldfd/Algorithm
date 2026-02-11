#include <string>
#include <vector>
#include <algorithm>

//정렬하고 붙인다. 질거같으면 + 비기면 다음사람이랑 붙는다. 비기는건.. 최대 승점이니까 지더라도 비기는건 피한다.

using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int answer = 0;
    int CurrentIndex = 0;
    const int Size = A.size();
    for(int b : B)
    {
        int a = A[CurrentIndex];
        while(a >= b && Size > CurrentIndex)
        {
            CurrentIndex++;
            a = A[CurrentIndex];
        }
        
        if(Size == CurrentIndex)
        {
            break;
        }
        
        answer++;
        CurrentIndex++;
    }
    
    return answer;
}