#include <string>
#include <vector>

using namespace std;

vector<int> Prevs;
vector<int> Nexts;
vector<int> Deleteds;

string Result;

int Selected;

void Up(int Num)
{
    for(int i = 0; i < Num; ++i)
    {
        int Prev = Prevs[Selected];
        if(Prev < 0)
        {
            return;
        }
        
        Selected = Prev;
    }
}

void Down(int Num)
{
    for(int i = 0; i < Num; ++i)
    {
        int Next = Nexts[Selected];
        if(Next < 0)
        {
            return;
        }
        
        Selected = Next;
    }
}

void Delete()
{
    int Prev = Prevs[Selected];
    int Next = Nexts[Selected];

    
    if(Prev != -1)
    {
        Nexts[Prev] = Next;
    }
    
    
    if(Next != -1)
    {
        Prevs[Next] = Prev;
    }
    
    Result[Selected] = 'X';
    
    Deleteds.push_back(Selected);
    Selected = (Next == -1) ? Prev : Next;
}

void Restore()
{
    if(Deleteds.empty())
    {
        return;
    }
    
    int Restored = Deleteds.back();
    Deleteds.pop_back();
    
    Result[Restored] = 'O';
    
    int Prev = Prevs[Restored];
    int Next = Nexts[Restored];
    
    if(Prev != -1)
    {
        Nexts[Prev] = Restored;
    }
    
    if(Next != -1)
    {
        Prevs[Next] = Restored;
    }
    
}

string solution(int n, int k, vector<string> cmd) 
{
    Result.append(n, 'O');

    Prevs.resize(n);
    Nexts.resize(n);
    for(int i = 0; i < n; ++i)
    {
        Prevs[i] = i - 1;
        Nexts[i] = i + 1;
    }
    
    Nexts.back() = -1;
    
    Selected = k;
    
    for(const string& c : cmd)
    {
        if(c[0] == 'C')
        {
            Delete();
        }
        else if(c[0] == 'Z')
        {
            Restore();
        }
        else if(c[0] == 'D')
        {
            Down(stoi(c.substr(2)));
        }
        else //if(c[0] == 'U')
        {
            Up(stoi(c.substr(2)));
        }
    }

    return Result;
}