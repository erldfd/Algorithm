#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int FindLastZero(const string& str)
{
    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(str[i] == '0')
        {
            return i;
        }
    }
    
    return -1;
}

vector<string> solution(vector<string> s) 
{
    for(string& str : s)
    {
        int Index = 0;
        int Count = 0;
        string Copy = "";
        
        for(const char c : str)
        {
            Copy += c;
            if(Copy.size() >= 3 && Copy.substr(Copy.size() - 3) == "110")
            {
                Count++;
                Copy.erase(Copy.size() - 3);
            }
        }
        
        Index = FindLastZero(Copy);
        string Temp = "";
        while(Count--)
        {
            Temp.append("110");
        }
        
        if(Index == -1)
        {
            str = Temp + Copy;
        }
        else
        {
            Copy.insert(Index + 1, Temp);
            str = Copy;
        }
    }
    
    return s;
}