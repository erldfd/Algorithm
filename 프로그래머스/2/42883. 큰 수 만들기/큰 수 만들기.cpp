#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) 
{
    // num, index
    vector<pair<char, int>> Rank;
    string answer = "";
    
    for(int i = 0; i < number.size(); ++i)
    {
        Rank.push_back(make_pair(number[i], i));
        sort(Rank.begin(), Rank.end(), [](const pair<char, int>& a, const pair<char, int>& b)
             {
                 return a.first < b.first;
             });
        
        if (Rank.size() > k)
        {
            Rank.pop_back();
        }
    }
    
    
    for(auto& R : Rank)
    {
        cout << R.first << ", " << R.second << " / ";
    }
    cout << endl;
    cout << number << endl;
    
    for(int i =0; i < Rank.size(); ++i)
    {
        remove(number.begin(), number.end(), Rank[i].first);
        number.pop_back();
        cout << number << endl;
    }
    
    return answer;
}