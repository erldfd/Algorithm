#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    unordered_map<string, int> PlayerPosition;
    
    for(int i = 0; i < players.size(); ++i)
    {
        PlayerPosition[players[i]] = i;
    }
    
    for(auto& calling : callings)
    {
        int callingPosition = PlayerPosition[calling];
        string Temp = players[callingPosition];
        
        players[callingPosition] = players[callingPosition - 1];
        players[callingPosition - 1]  = Temp;
        
        PlayerPosition[calling] = callingPosition - 1;
        PlayerPosition[players[callingPosition]] = callingPosition;
    }
    
    return players;
}