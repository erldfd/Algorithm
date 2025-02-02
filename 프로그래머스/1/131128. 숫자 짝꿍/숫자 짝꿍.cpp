#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string X, string Y) 
{
    vector<int> NumberCheckerX = vector<int>(10, 0);
    priority_queue<char> PairList;

    string answer = "";
    
    for(const char& c : X)
    {
        int& NumberCount = NumberCheckerX[c - '0'];
        NumberCount++;
        
    }
    
    for(const char& c : Y)
    {
        int& NumberCount = NumberCheckerX[c - '0'];
        
        if(NumberCount > 0)
        {
            NumberCount--;
            PairList.push(c);
        }
    }
    
    int IteratingCount = PairList.size();
    
    if (IteratingCount == 0)
    {
        return "-1";
    }
    
    if (PairList.top() == '0')
    {
        return "0";
    }
    
    for(int i = 0; i < IteratingCount; ++i)
    {
        answer += PairList.top();
        PairList.pop();
    }
    
    return answer;
}
