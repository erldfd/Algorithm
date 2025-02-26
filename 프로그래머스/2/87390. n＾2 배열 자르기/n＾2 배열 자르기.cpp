#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    int arraySize = right - left + 1;
    vector<int> arr(arraySize);

    for (int i = 0; i < arraySize; ++i)
    {
        int coordX = left / n;
        int coordY = left % n;
        
        if(coordX >= coordY)
        {
            arr[i] = coordX + 1;
        }
        else
        {
            arr[i] = coordY + 1;
        }
        
        left++;
    }

    return arr;
}