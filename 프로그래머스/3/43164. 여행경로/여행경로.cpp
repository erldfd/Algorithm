#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool dfs(const string& cur,
         map<string, vector<pair<string,int>>>& adj,
         vector<bool>& used,
         vector<string>& route,
         int ticketCount,
         vector<string>& answer,
         bool& found)
{
    if (found) return true; // 이미 해답 찾았으면 빠져나오기

    if ((int)route.size() == ticketCount + 1) {
        // 모든 티켓 사용 완료 -> 해답
        answer = route;
        found = true;
        return true;
    }

    auto &neighbors = adj[cur];
    for (size_t i = 0; i < neighbors.size(); ++i) {
        const string& nxt = neighbors[i].first;
        int idx = neighbors[i].second;
        if (used[idx]) continue;

        used[idx] = true;
        route.push_back(nxt);

        dfs(nxt, adj, used, route, ticketCount, answer, found);

        if (found) return true; // 찾았으면 중간에서 바로 반환

        // 백트래킹
        route.pop_back();
        used[idx] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 1) 인접리스트 (출발 -> [(도착, 티켓인덱스)...]), 도착은 나중에 정렬
    map<string, vector<pair<string,int>>> adj;
    int m = tickets.size();
    for (int i = 0; i < m; ++i) {
        adj[tickets[i][0]].push_back({tickets[i][1], i});
    }

    // 2) 각 출발지의 도착지들을 목적지 사전순으로 정렬
    for (auto &p : adj) {
        auto &vec = p.second;
        sort(vec.begin(), vec.end(), [](const pair<string,int>& a, const pair<string,int>& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
    }

    // 3) DFS 준비
    vector<bool> used(m, false);
    vector<string> route;
    vector<string> answer;
    bool found = false;

    // 시작은 ICN
    route.push_back("ICN");
    dfs("ICN", adj, used, route, m, answer, found);

    return answer;
}
