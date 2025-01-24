#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    vector<int> Days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> Months = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int PassedDays = 0;
    
    for(int i = 0; i < a - 1; ++i)
    {
        PassedDays += Days[i];
    }
    
    PassedDays += b - 1;
    
    string answer = Months[PassedDays % 7];
    return answer;
}