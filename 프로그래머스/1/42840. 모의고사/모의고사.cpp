#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    
    int AnswersSize = answers.size();
    
    int CorrectCount1 = 0;
    int CorrectCount2 = 0;
    int CorrectCount3 = 0;
    
    for(int i = 0 ; i < AnswersSize; ++ i)
    {
        int Answer = answers[i];
        if(Answer == i % 5 + 1)
        {
            CorrectCount1++;
        }
        
        int SelectedNumber2 = 0;
        
        if(i % 2 == 0)
        {
            SelectedNumber2 = 2;
        }
        else
        {
            if(i % 8 == 1)
            {
                SelectedNumber2 = 1;
            }
            else
            {
                SelectedNumber2 = (i % 8 / 2) + 2;
            }
        }
        
        if(Answer == SelectedNumber2)
        {
            CorrectCount2++;
        }
        
        int SelectedNumber3 = 0;
        
        int Index = i % 10 / 2;
        
        if(Index == 0)
        {
            SelectedNumber3 = 3;
        }
        else
        {
            SelectedNumber3 = Index;
            
            if(Index > 2)
            {
                SelectedNumber3++;
            }
        }
        
        if(Answer == SelectedNumber3)
        {
            CorrectCount3++;
        }
    }
    
    int Max = max(CorrectCount1, CorrectCount2);
    Max = max(Max, CorrectCount3);
    
    if(CorrectCount1 == Max)
    {
        answer.push_back(1);
    }
    
    if(CorrectCount2 == Max)
    {
        answer.push_back(2);
    }
    
    if(CorrectCount3 == Max)
    {
        answer.push_back(3);
    }
    
    return answer;
}