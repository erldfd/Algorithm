#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> answer(2, -1);
    
    int StartIndex = 0;
    int EndIndex = 0;
    
    int SumOfPermutation = sequence[0];
    
    while(true)
    {
        if(SumOfPermutation > k)
        {
            SumOfPermutation -= sequence[StartIndex++];

            if(StartIndex > EndIndex)
            {
                break;
            }
        }
        else if(SumOfPermutation < k)
        {
            EndIndex++;
            
            if(EndIndex >= sequence.size())
            {
                break;
            }
            
            SumOfPermutation += sequence[EndIndex];
        }
        else
        {
            if(answer[1] == -1 || answer[1] - answer[0] != EndIndex - StartIndex)
            {
                answer[0] = StartIndex;
                answer[1] = EndIndex;
            }
            
            SumOfPermutation -= sequence[StartIndex++];

            if(StartIndex > EndIndex)
            {
                break;
            }
        }
    }
    
    return answer;
}