#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct User
{
    unordered_set<string> ReportingMeUser;
    int ReportedCount = 0;
    int MailCount = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    unordered_map<string, User> IDWithUserMap;
    
    for(auto& id : id_list)
    {
        IDWithUserMap[id] = User();
    }
    
    for(auto& r : report)
    {
        stringstream ss(r);
        
        string Reporter;
        string Reported;
        
        ss >> Reporter >> Reported;
        
        if(IDWithUserMap[Reported].ReportingMeUser.find(Reporter) == IDWithUserMap[Reported].ReportingMeUser.end())
        {
            IDWithUserMap[Reported].ReportedCount++;
            IDWithUserMap[Reported].ReportingMeUser.insert(Reporter);
        }
        
    }
    
    for(auto& IDWithUser : IDWithUserMap)
    {
        if(IDWithUser.second.ReportedCount >= k)
        {
            for(auto& ID : IDWithUser.second.ReportingMeUser)
            {
                IDWithUserMap[ID].MailCount++;
            }
        }
    }
    
    vector<int> answer;
    
    for(auto& id : id_list)
    {
        answer.push_back(IDWithUserMap[id].MailCount);
    }
    
    return answer;
}