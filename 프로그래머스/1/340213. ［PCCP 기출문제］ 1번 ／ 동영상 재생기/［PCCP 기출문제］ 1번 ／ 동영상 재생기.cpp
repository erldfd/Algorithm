#include <string>
#include <vector>

using namespace std;

int TimeStrToSec(const string& timeStr)
{
    string minStr = "";
    minStr += timeStr[0];
    minStr += timeStr[1];
    
    int min = stoi(minStr);
    
    string secStr = "";
    secStr += timeStr[3];
    secStr += timeStr[4];
    
    int sec = stoi(secStr);

    int totalSec = min * 60 + sec;
    
    return totalSec;
}

string SecToTimeStr(int second)
{
    string timeStr = "";
    
    int min = second / 60;
    if (min < 10)
    {
        timeStr = "0";
    }
    
    timeStr += to_string(min);
    timeStr += ":";
    
    second -= min * 60;
    
    if (second < 10)
    {
        timeStr += "0";
    }
    
    timeStr += to_string(second);
    
    return timeStr;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{ 
    int vedio_len_sec = TimeStrToSec(video_len);
    int pos_sec = TimeStrToSec(pos);
    int op_start_sec = TimeStrToSec(op_start);
    int op_end_sec = TimeStrToSec(op_end);
    
    if (pos_sec >= op_start_sec && pos_sec <= op_end_sec)
    {
        pos_sec = op_end_sec;
    }
    
    for(auto& command : commands)
    {
        if (pos_sec >= op_start_sec && pos_sec <= op_end_sec)
        {
            pos_sec = op_end_sec;
        }
        
        if (command == "next")
        {
            pos_sec += 10;
            
            if (pos_sec > vedio_len_sec)
            {
                pos_sec = vedio_len_sec;
            }
        }
        else if(command == "prev")
        {
            pos_sec -= 10;
            
            if (pos_sec < 0) 
            {
                pos_sec = 0;
            }
        }
        
        if (pos_sec >= op_start_sec && pos_sec <= op_end_sec)
        {
            pos_sec = op_end_sec;
        }
    }
    
    string answer = SecToTimeStr(pos_sec);
    
    return answer;
}