#include <string>
#include <vector>

using namespace std;

int ZeroCount = 0;
int OneCount = 0;

bool IsAllSame(const vector<vector<int>>& arr, int StartX, int StartY, int Size, bool& bIsZero)
{
    for(int x = StartX; x < StartX + Size; ++x)
    {
        for(int y = StartY; y < StartY + Size; ++y)
        {
            if(arr[x][y] == arr[StartX][StartY])
            {
                continue;
            }
            
            return false;
        }
    }
    
    bIsZero = (arr[StartX][StartY] == 0);
    return true;
}


void Divide(const vector<vector<int>>& arr, int StartX, int StartY, int Size)
{
    bool bIsZero = false;
    if(IsAllSame(arr, StartX, StartY, Size, bIsZero))
    {
        (bIsZero) ? ZeroCount++ : OneCount++;
        return;
    }
    
    int Half = Size / 2;
    Divide(arr, StartX, StartY, Half);
    Divide(arr, StartX + Half, StartY, Half);
    Divide(arr, StartX, StartY + Half, Half);
    Divide(arr, StartX + Half, StartY + Half, Half);
}

vector<int> solution(vector<vector<int>> arr) 
{
    Divide(arr, 0, 0, arr.size());
    return {ZeroCount, OneCount};
}