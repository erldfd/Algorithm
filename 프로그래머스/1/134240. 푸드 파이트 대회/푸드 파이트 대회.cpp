#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) 
{
    string answer = "";
    
    for(int i = 1; i < food.size(); ++i)
    {
        if(food[i] % 2 != 0)
        {
            food[i]--;
        }
        
        int FoodCount = food[i];
        string ReservedFood = "";
        
        for(int j = 0; j < FoodCount; ++j)
        {
            ReservedFood += i + '0';
        }

        answer.insert(answer.size() / 2, ReservedFood);
    }
    
    answer.insert(answer.size() / 2, "0");
    
    return answer;
}