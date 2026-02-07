#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<int, unordered_set<string>> ChancesByUsers;

set<string> VisitedChances;
unordered_set<int> VisitedUsers;

set<set<string>> Sets;

bool IsPossible(const string& A, const string& B)
{
    const int Size = A.size();
    if(Size != B.size())
    {
        return false;
    }
    
    for(int i = 0; i < Size; ++i)
    {
        if(A[i] == B[i] || A[i] == '*' || B[i] == '*')
        {
            continue;
        }
        
        return false;
    }
    
    return true;
}

void Combination(int Depth)
{
    if(Depth == ChancesByUsers.size())
    {
        Sets.insert(VisitedChances);
        return;
    }
    
    for(const auto& [User, Chances] : ChancesByUsers)
    {
        if(VisitedUsers.find(User) != VisitedUsers.end())
        {
            continue;
        }
        
        VisitedUsers.insert(User);
        
        for(const string& Chance : Chances)
        {
            if(VisitedChances.find(Chance) != VisitedChances.end())
            {
                continue;
            }
            
            VisitedChances.insert(Chance);
            Combination(Depth + 1);
            VisitedChances.erase(Chance);
        }
        
        VisitedUsers.erase(User);
        return;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    for(const string& user : user_id)
    {
        for(int i = 0; i < banned_id.size(); ++i)
        {
            if(IsPossible(user, banned_id[i]))
            {
                ChancesByUsers[i].insert(user);
            }
        }
    }
    
    Combination(0);
    
    return Sets.size();
}