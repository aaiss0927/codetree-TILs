#include <iostream>
using namespace std;

int n, m;
// n: v_num, m: e_num
int graph[1001][1001] = {0, };
bool visited[1001] = {false, };

int cnt = 0;

void DFS(int vertex) {
    for (int i = 1; i <= n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            cnt++;
            visited[i] = true;
            DFS(i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;

        graph[s][e] = graph[e][s] = 1;
    }

    visited[1] = true;
    DFS(1);

    cout << cnt;
}