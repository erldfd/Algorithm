#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> Dictionary;

string FindLongestString(const string& Target)
{
    const int Length = Target.size();
    string Longest = "";
    for(int i = 0; i < Length; ++i)
    {
        Longest += Target[Length - i - 1];
        if(Dictionary.find(Longest) == Dictionary.end())
        {
            Longest.pop_back();
            return Longest;
        }
    }
    
    return Longest;
}

vector<int> solution(string msg) 
{
    reverse(msg.begin(), msg.end());
    
    for(int i = 0; i < 26; ++i)
    {
        string Temp = "";
        Temp.push_back(i + 'A');
        Dictionary[Temp] = i + 1;
    }
    
    vector<int> answer;
    
    while(msg.size() > 0)
    {
        string w = FindLongestString(msg);
        answer.push_back(Dictionary[w]);
        
        for(int i = 0; i < w.size(); ++i)
        {
            msg.pop_back();
        }
        
        if(msg.size() > 0)
        {
            string wc = w;
            wc += msg.back();
            Dictionary[wc] = Dictionary.size() + 1;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}

/*

input = KAKAO;

 w = K;
 print = {11, };
 input = AKAO;
 c = A;
 wc = KA;
 KA = 27;
 
 w = A;
 print = {11, 1};
 input = KAO;
 c = K;
 wc = AK;
 AK = 28;
 
 w = KA
 print = {11, 1, 27};
 input = O;
 c = O;
 wc = KAO;
 KAO = 29;
 
 w = O;
 print = {11, 1, 27, 15};
 input = nil; -> terminate;
 
 
 input = ABABABABABABABAB;
 
 
 w = A;
 print = {1, };
 input = BABABABABABABAB;
 c = B;
 wc = AB;
 AB = 27;
 
 w = B;
 print = {1, 2};
 input = ABABABABABABAB;
 c = A;

*/