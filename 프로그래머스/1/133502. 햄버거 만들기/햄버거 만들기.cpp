#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) 
{
    vector<string> IngerdienetPot;
    
    int answer = 0;
    
    for(int i = 0; i < ingredient.size(); ++i)
    {
        string NewIngredient = "";
        NewIngredient += ingredient[i] + '0';
        
        if(IngerdienetPot.empty())
        {
            IngerdienetPot.push_back(NewIngredient);
            continue;
        }
        
        string& Top = IngerdienetPot.back();
        
        if(Top == "1" && NewIngredient == "2" ||
          Top == "12" && NewIngredient == "3")
        {
            Top += NewIngredient;
        }
        else if(Top == "123" && NewIngredient == "1")
        {
            answer++;
            IngerdienetPot.pop_back();
        }
        else
        {
            IngerdienetPot.push_back(NewIngredient);
        }
    }
    
    return answer;
}