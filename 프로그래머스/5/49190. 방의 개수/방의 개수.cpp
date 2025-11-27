#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;

struct Edge
{
    Edge(const pair<int, int>& Coord1, const pair<int, int>& Coord2)
    {
        Coords.clear();
        Coords.reserve(2);
        Coords.push_back(Coord1);
        Coords.push_back(Coord2);
        sort(Coords.begin(), Coords.end(), [](const pair<int, int>& A, const pair<int, int>& B)
             {
                 if(A.first == B.first)
                 {
                     return A.second < B.second;
                 }
                 
                 return A.first < B.first;
             });
    }
    
    vector<pair<int, int>> Coords;

    bool operator<(const Edge& Other) const
    {
        return Coords < Other.Coords;
    }
};

int Dx[] {-1, -1, 0, 1, 1, 1, 0, -1};
int Dy[] {0, 1, 1, 1, 0, -1, -1, -1};

set<pair<int, int>> Visited;
set<Edge> Edges;

int solution(vector<int> arrows) 
{
    int X = 0;
    int Y = 0;
    Visited.insert({X, Y});
    
    int answer = 0;

    for(int a : arrows)
    {
        for(int i = 0; i < 2; ++i)
        {
            int NextX = X + Dx[a];
            int NextY = Y + Dy[a];

            auto [It, IsNotVisited] = Visited.insert({NextX, NextY});
            auto [It2, IsNewEdge] = Edges.insert(Edge({X, Y}, {NextX, NextY}));

            X = NextX;
            Y = NextY;
        }
    }
    
    int VertexCount = Visited.size();
    int EdgeCount = Edges.size();

    return 1 - VertexCount + EdgeCount;
}