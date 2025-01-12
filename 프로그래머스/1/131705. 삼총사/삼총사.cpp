#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) 
{
    int answer = 0;
    
    int NumSize = number.size();
    
    for(int i = 0; i < NumSize; ++i)
    {
        int FirstSelection = number[i];
        
        for(int j = i + 1; j < NumSize; ++j)
        {
            int SecondSelection = number[j];
            
            if(i == j)
            {
                continue;
            }
            
            for(int k = j + 1; k < NumSize; ++k)
            {
                if(i == k || j == k)
                {
                    continue;
                }
                
                int ThirdSelection = number[k];
                
                if(FirstSelection + SecondSelection + ThirdSelection == 0)
                {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}