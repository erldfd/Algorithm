#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> order) 
{
    vector<int> Main(order.begin(), order.end());
    sort(Main.rbegin(), Main.rend());

    vector<int>Sub;
    
    int answer = 0;

    while(Main.empty() == false || Sub.empty() == false)
    {
        if(Main.empty() == false && Main.back() == order[answer])
        {
            answer++;
            Main.pop_back();
        }
        else if(Sub.empty() == false && Sub.back() == order[answer])
        {
            answer++;
            Sub.pop_back();
        }
        else if(Main.empty() == false)
        {
            Sub.push_back(Main.back());
            Main.pop_back();
        }
        else
        {
            break;
        }
    }
    
    return answer;
}