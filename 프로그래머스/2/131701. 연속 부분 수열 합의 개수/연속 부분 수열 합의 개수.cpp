#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) 
{ 
    int ElementSize = elements.size();
    unordered_set<int> SumCountSet;
    
    for(int Length = 1; Length <= ElementSize; ++Length)
    {
        for(int StartIndex = 0; StartIndex < ElementSize; ++StartIndex)
        {
            int Sum = 0;
            
            for(int i = 0; i < Length; ++i)
            {
                int Index = (i + StartIndex) % ElementSize;
                
                Sum += elements[Index];
            }
            
            SumCountSet.insert(Sum);
        }
        
    }
    
    return SumCountSet.size();
}