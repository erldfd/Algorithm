#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 마지막 head 지점, 마지막 number 지점 인덱스 반환
pair<int, int> FindIndex(const string& FileName)
{
    int LastHeadIndex = 0;
    for(int i = 0; i < FileName.size(); ++i)
    {
        if(isdigit(FileName[i]))
        {
            LastHeadIndex = i - 1;
            break;
        }
    }
    
    int LastNumberIndex = 0;
    for(int i = LastHeadIndex + 1; i < FileName.size();++i)
    {
        if(isdigit(FileName[i]))
        {
            continue;
        }
        
        LastNumberIndex = i - 1;
        break;
    }
    
    return {LastHeadIndex, LastNumberIndex};
}

vector<string> solution(vector<string> files) 
{
    stable_sort(files.begin(), files.end(), [](const string& A, const string& B)
         {
             auto [HeadIndexA, NumberIndexA] = FindIndex(A);
             auto [HeadIndexB, NumberIndexB] = FindIndex(B);
             
             string HeadA = A.substr(0, HeadIndexA + 1);
             string NumberA = A.substr(HeadIndexA + 1, NumberIndexA - HeadIndexA);
             string TailA = A.substr(NumberIndexA + 1);

             string HeadB = B.substr(0, HeadIndexB + 1);
             string NumberB = B.substr(HeadIndexB + 1, NumberIndexB - HeadIndexB);
             string TailB = B.substr(NumberIndexB + 1);
             
             transform(HeadA.begin(), HeadA.end(), HeadA.begin(), ::toupper);
             transform(HeadB.begin(), HeadB.end(), HeadB.begin(), ::toupper);
             
             if(HeadA == HeadB)
             {
                 int NA = stoi(NumberA);
                 int NB = stoi(NumberB);
                 
                 if(NA == NB)
                 {
                     return false;
                 }
                 else
                 {
                     return NA < NB;
                 }
             }
             
             return HeadA < HeadB;
         });

    return files;
}