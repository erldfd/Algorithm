#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> TermMap;

bool IsExpired(const string& today, const string& privacy)
{
    stringstream TodaySS(today);
    
    string TodayYear = "";
    getline(TodaySS, TodayYear, '.');
    
    string TodayMonth = "";
    getline(TodaySS, TodayMonth, '.');

    string TodayDay = "";
    getline(TodaySS, TodayDay, '.');
    
    int TodayNum = stoi(TodayYear) * 12 * 28;
    TodayNum += stoi(TodayMonth) * 28;
    TodayNum += stoi(TodayDay);
    
    stringstream PrivacySS(privacy);
    
    string PrivacyYear = "";
    getline(PrivacySS, PrivacyYear, '.');
    
    string PrivacyMonth = "";
    getline(PrivacySS, PrivacyMonth, '.');
    
    string PrivacyDay = "";
    getline(PrivacySS, PrivacyDay, ' ');
    
    string TermType = "";
    getline(PrivacySS, TermType, ' ');
    
    int ExpiredDayNum = stoi(PrivacyYear) * 12 * 28;
    ExpiredDayNum += stoi(PrivacyMonth) * 28;
    ExpiredDayNum += stoi(PrivacyDay);
    ExpiredDayNum += TermMap[TermType] * 28;

    return (TodayNum - ExpiredDayNum >= 0);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    for(auto& term : terms)
    {
        stringstream ss(term);
        string Temp = "";
        getline(ss, Temp, ' ');
        
        string NumString = "";
        getline(ss, NumString, ' ');
        int Num = stoi(NumString);
        
        TermMap[Temp] = Num;
    }
    
    vector<int> answer;
    
    for(int i =0; i < privacies.size(); ++i)
    {
        if(IsExpired(today, privacies[i]))
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}