#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetGCD(int Num1, int Num2)
{
    int Bigger = max(Num1, Num2);
    int Smaller = min(Num1, Num2);
    
    int R = 0;
    
    do
    {
        R = Bigger % Smaller;
        
        Bigger = Smaller;
        Smaller = R;
        
    }
    while(Smaller != 0);
    
        
    return Bigger;
}

// 어케하더라
int GetLCM(int Num1, int Num2)
{
    int Bigger = max(Num1, Num2);
    int Smaller = min(Num1, Num2);
    
    int Candidate = Bigger;

    while(Candidate % Smaller != 0)
    {
        Candidate += Bigger;
    }
    
    return Candidate;
}


vector<int> solution(int n, int m) 
{
    vector<int> answer;
    
    answer.push_back(GetGCD(n, m));
    answer.push_back(GetLCM(n, m));
    
    return answer;
}