#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

int DayToNum(const string& Day)
{
    stringstream ss(Day);
    string Temp;
    
    getline(ss, Temp, '.');
    int Year = stoi(Temp) * 28 * 12;
    
    getline(ss, Temp, '.');
    int Month = stoi(Temp) * 28;
    
    getline(ss, Temp, '.');
    int DayNum = stoi(Temp);
    
    return Year + Month + DayNum;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    unordered_map<char, int> Rules;
    
    for(const string& term : terms)
    {
        Rules[term[0]] = stoi(term.substr(1));
    }
    
    int TodayNum = DayToNum(today);
    
    vector<int> answer;
    int Index = 0;
    for(string& p : privacies)
    {
        Index++;
        int RuleNum = Rules[p.back()] * 28;
        p.pop_back();
        
        int Day = DayToNum(p) + RuleNum - 1;
        
        if(TodayNum - Day > 0)
        {
            answer.push_back(Index);
        }
    }
    
    return answer;
}