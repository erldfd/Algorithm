#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    int Min = 2100000000;
    int Max = -2100000000;
    
    stringstream ss(s);
        
    while(true)
    {
        string NumStr = "";
        ss >> NumStr;
        
        if(NumStr == "")
        {
            break;
        }
        
        int Num = stoll(NumStr);
        
        Min = min(Min, Num);
        Max = max(Max, Num);
    }
    
    return to_string(Min) + " " + to_string(Max);
}