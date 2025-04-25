#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Array;

int TotalZeroCount = 0;
int TotalOneCount = 0;

bool TryCompress(int StartX, int StartY, int SizeX, int SizeY, int& OutZeroCount, int& OutOneCount)
{
    int First = Array[StartX][StartY];
    int TempZeroCount = 0;
    int TempOneCount = 0;

    for(int i = StartX; i < StartX + SizeX; ++i)
    {
        for(int j = StartY; j < StartY + SizeY; ++j)
        {
            int Current = Array[i][j];
            
            if(Current == 0)
            {
                TempZeroCount++;
            }
            else // if(Current == 1)
            {
                TempOneCount++;
            }
            
            if(First != Current)
            {
                return false;
            }
        }
    }
    
    if(TempZeroCount == 0)
    {
        OutZeroCount = 0;
        OutOneCount = 1;
    }
    else //if(TempOneCount == 0)
    {
        OutZeroCount = 1;
        OutOneCount = 0;
    }
    
    return true;
}

void DFS(int StartX, int StartY, int SizeX, int SizeY)
{ 
    int ZeroCount = 0;
    int OneCount = 0;
    
    if(TryCompress(StartX, StartY, SizeX, SizeY, ZeroCount, OneCount))
    {
        TotalZeroCount += ZeroCount;
        TotalOneCount += OneCount;
        return;
    }
    
    DFS(StartX, StartY, SizeX / 2, SizeY / 2);
    DFS(StartX, StartY + SizeY / 2, SizeX / 2, SizeY / 2);
    DFS(StartX + SizeX / 2, StartY, SizeX / 2, SizeY / 2);
    DFS(StartX + SizeX / 2, StartY + SizeY / 2, SizeX / 2, SizeY / 2);
}

vector<int> solution(vector<vector<int>> arr) 
{
    Array = arr;
    DFS(0, 0, arr.size(), arr[0].size());
    
    return {TotalZeroCount, TotalOneCount};
}