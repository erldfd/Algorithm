#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) 
{
    vector<int> answer;
    
    for(auto& Ball : balls)
    {
        cout << "=============" << endl;
        
        vector<pair<int, int>> Coords;
        
        if((startX > Ball[0] && startY == Ball[1]) == false)
        {
            Coords.push_back({-Ball[0], Ball[1]});
        }
        
        if((startX < Ball[0] && startY == Ball[1]) == false)
        {
            Coords.push_back({2 * m - Ball[0], Ball[1]});
        }
        
        if((startY < Ball[1] && startX == Ball[0]) == false)
        {
            Coords.push_back({Ball[0], 2 * n - Ball[1]});
        }
        
        if((startY > Ball[1] && startX == Ball[0]) == false)
        {
            Coords.push_back({Ball[0], -Ball[1]});
        }
        
        int Min = 4 * (n * n + m * m);
        
        for(auto& Coord : Coords)
        {
            int Dist = (Coord.first - startX) * (Coord.first - startX) + (Coord.second - startY) * (Coord.second - startY);
            cout << Dist << endl;
            Min = min(Min, Dist);
        }
        
        answer.push_back(Min);
    }
    
    return answer;
}