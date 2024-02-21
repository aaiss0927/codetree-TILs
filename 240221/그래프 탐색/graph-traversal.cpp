#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int vertex) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        int cur_v = graph[vertex][i];
        if (!visited[cur_v]) {
            cnt++;
            visited[cur_v] = true;
            DFS(cur_v);
        }
    }
}

int main() {
    cin >> n >> m;

    graph = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool>(n + 1, false);

    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    visited[1] = true;
    DFS(1);

    cout << cnt;
}