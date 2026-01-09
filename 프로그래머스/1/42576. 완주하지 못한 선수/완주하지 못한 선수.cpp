#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    unordered_map<string, int> People;
    
    for(const string& p : participant)
    {
        People[p]++;
    }
    
    for(const string& c : completion)
    {
        People[c]--;
        if(People[c] == 0)
        {
            People.erase(c);
        }
    }
    
    string answer = "";
    
    for(const auto [p, c] : People)
    {
        answer = p;
        break;
    }
    
    return answer;
}