#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void SearchFoods(vector<string>& OutMaps, int X, int Y, int& OutFoodScore)
{
    if(X < 0 || Y < 0 || X >= OutMaps.size() || Y >= OutMaps[0].size())
    {
        return;
    }
    
    if(OutMaps[X][Y] == 'X')
    {
        return;
    }
    
    OutFoodScore += OutMaps[X][Y] - '0';
    OutMaps[X][Y] = 'X';
    
    SearchFoods(OutMaps, X + 1, Y, OutFoodScore);
    SearchFoods(OutMaps, X - 1, Y, OutFoodScore);
    SearchFoods(OutMaps, X, Y + 1, OutFoodScore);
    SearchFoods(OutMaps, X, Y - 1, OutFoodScore);
}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    
    for(int i =0; i < maps.size(); ++i)
    {
        for(int j =0; j < maps[0].size(); ++j)
        {
            if(maps[i][j] != 'X')
            {
                int FoodScore = 0;
                SearchFoods(maps, i, j, FoodScore);
                answer.push_back(FoodScore);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty())
    {
        return { -1 };
    }
    
    return answer;
}