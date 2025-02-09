#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    int lux = 99;
    int luy = 99;
    int rdx = 0;
    int rdy = 0;
    
    for(int i =0 ; i < wallpaper.size(); ++i)
    {
        for(int j = 0; j < wallpaper[i].size(); ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i);
                rdy = max(rdy, j);
            }
        }
    }
    
    return {lux, luy, rdx + 1, rdy + 1};
}