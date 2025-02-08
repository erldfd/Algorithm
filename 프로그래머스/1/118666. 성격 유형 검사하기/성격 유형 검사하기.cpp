#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    unordered_map<string, int> TypeScore = 
    {
        {"RT", 0},
        {"CF", 0},
        {"JM", 0}, 
        {"AN", 0}, 
    };
    
    for(int i = 0 ; i < survey.size(); ++i)
    {
        string s = survey[i];
        
        int Score = choices[i] - 4;
        
        if(TypeScore.find(s) == TypeScore.end())
        {
            s = survey[i][1];
            s += survey[i][0];
            
            Score = -Score;
        }
        
        TypeScore[s] += Score;
    }
    
    string answer = "";
    
    if(TypeScore["RT"] > 0)
    {
        answer +='T';
    }
    else
    {
        answer +='R';
    }
    
    if(TypeScore["CF"] > 0)
    {
        answer +='F';
    }
    else
    {
        answer +='C';
    }
    
    if(TypeScore["JM"] > 0)
    {
        answer +='M';
    }
    else
    {
        answer +='J';
    }
    
    if(TypeScore["AN"] > 0)
    {
        answer +='N';
    }
    else
    {
        answer +='A';
    }
    
    return answer;
}