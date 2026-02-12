#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000000000;
vector<vector<int>> DP;
int MaxAlp, MaxCop;

bool CanSolve(int Alp, int Cop, const vector<int>& p)
{
    return Alp >= p[0] && Cop >= p[1];
}

// return cost
int Solve(int CurrAlp, int CurrCop, const vector<vector<int>>& problems)
{
    if(CurrAlp >= MaxAlp && CurrCop >= MaxCop)
    {
        return 0;
    }
    
    int& CurrCost = DP[CurrAlp][CurrCop];
    if(CurrCost != -1)
    {
        return CurrCost;
    }
    
    CurrCost = MAX;
    
    for(const vector<int>& p : problems)
    {
        if(CanSolve(CurrAlp, CurrCop, p) == false)
        {
            continue;
        }
        
        int NextAlp = min(MaxAlp, CurrAlp + p[2]);
        int NextCop = min(MaxCop, CurrCop + p[3]);
        
        CurrCost = min(CurrCost, Solve(NextAlp, NextCop, problems) + p[4]);
    }
    
    CurrCost = min(CurrCost, min(Solve(min(MaxAlp, CurrAlp + 1), CurrCop, problems) + 1, Solve(CurrAlp, min(MaxCop, CurrCop + 1), problems) + 1));
    
    return CurrCost;
}

int solution(int alp, int cop, vector<vector<int>> problems) 
{
    for(const vector<int>& p : problems)
    {
        MaxAlp = max(MaxAlp, p[0]);
        MaxCop = max(MaxCop, p[1]);
    }
    
    DP.resize(151, vector<int>(151, -1));
    
    return Solve(alp, cop, problems);
}