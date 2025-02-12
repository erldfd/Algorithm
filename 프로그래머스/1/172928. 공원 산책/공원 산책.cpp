#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    int CurrentPosX = -1;
    int CurrentPosY = -1;
    int ParkHeight = park.size();
    int ParkWidth = park[0].size();
    
    for(int i =0; i < ParkHeight; ++i)
    {
        for(int j = 0; j < ParkWidth; ++j)
        {
            if(park[i][j] == 'S')
            {
                CurrentPosX = i;
                CurrentPosY = j;
                break;
            }
        }
        
        if(CurrentPosX != -1)
        {
            break;
        }
    }
    
    cout << CurrentPosX << " , " << CurrentPosY << endl;
    
    for(auto& Route : routes)
    {
        int MoveCount = Route[2] - '0';
        int OriginX = CurrentPosX;
        int OriginY = CurrentPosY;
        
        while(MoveCount--)
        {
            if(Route[0] == 'E')
            {
                if (CurrentPosY + 1 >= ParkWidth)
                {
                    CurrentPosY = OriginY;
                    break;
                }

                if(park[CurrentPosX][CurrentPosY + 1] == 'X')
                {
                    CurrentPosY = OriginY;
                    break;
                }

                CurrentPosY += 1;
            }
            else if(Route[0] == 'W')
            {
                if (CurrentPosY <= 0)
                {
                    CurrentPosY = OriginY;
                    break;
                }

                if(park[CurrentPosX][CurrentPosY - 1] == 'X')
                {
                    CurrentPosY = OriginY;
                    break;
                }

                CurrentPosY -= 1;
            }
            else if(Route[0] == 'S')
            {
                if (CurrentPosX + 1 >= ParkHeight)
                {
                    CurrentPosX = OriginX;
                    break;
                }

                if(park[CurrentPosX + 1][CurrentPosY] == 'X')
                {
                    CurrentPosX = OriginX;
                    break;
                }

                CurrentPosX += 1;
            }
            else if(Route[0] == 'N')
            {
                if (CurrentPosX <= 0)
                {
                    CurrentPosX = OriginX;
                    break;
                }

                if(park[CurrentPosX - 1][CurrentPosY] == 'X')
                {
                    CurrentPosX = OriginX;
                    break;
                }

                CurrentPosX -= 1;
            }
        }
        
        cout << CurrentPosX << " , " << CurrentPosY << endl;
    }
    
    return {CurrentPosX, CurrentPosY};
}