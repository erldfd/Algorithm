#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) 
{
    // stringNumber, pair<charNumber, strignSize>
    unordered_map<string, pair<char, int>> numberMap;
    
    string numberString = "";

    numberMap["ze"] = pair('0', 4);
    numberMap["on"] = pair('1', 3);
    numberMap["tw"] = pair('2', 3);
    numberMap["th"] = pair('3', 5);
    numberMap["fo"] = pair('4', 4);
    numberMap["fi"] = pair('5', 4);
    numberMap["si"] = pair('6', 3);
    numberMap["se"] = pair('7', 5);
    numberMap["ei"] = pair('8', 5);
    numberMap["ni"] = pair('9', 4);
    
    for(int i = 0 ; i < s.size(); ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            numberString +=s[i];
            continue;
        }
        
        numberString+=numberMap[s.substr(i, 2)].first;
        i +=numberMap[s.substr(i, 2)].second -1;
    }
        
    return stoi(numberString);
}