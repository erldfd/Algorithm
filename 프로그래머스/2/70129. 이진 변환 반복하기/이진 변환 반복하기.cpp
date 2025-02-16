#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string NumToBinary(int Num)
{
    string Result = "";
    
    while(Num > 0)
    {
        Result.insert(Result.begin(), Num % 2 + '0');
        Num /= 2;
    }
    
    return Result;
}

// return : removed Count
int RemoveZero(string StrNum, string& OutResult)
{
    auto It = remove(StrNum.begin(), StrNum.end(), '0');
    
    int RemovedCount = StrNum.end() - It;
    
    StrNum.erase(It, StrNum.end());
    
    OutResult = StrNum;
    return RemovedCount;
}

vector<int> solution(string s) 
{
    int TransformCount = 0;
    int RemovedCount = 0;
    
    while(s != "1")
    {
        RemovedCount += RemoveZero(s, s);
        s = NumToBinary(s.size());
        TransformCount++;
        
    }
    
    return {TransformCount, RemovedCount};
}