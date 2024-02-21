#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
bool visited[25][25] = {false, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
    if (!is_range(x, y)) {
        return false;
    }

    if (grid[x][y] == 0) {
        return false;
    }

    if (visited[x][y]) {
        return false;
    }

    return true;
}

int cnt_town = 0;
int cnt_town_person;
vector<int> cnt_town_people;

void DFS(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (can_go(n_x, n_y)) {
        cnt_town_person++;
        visited[n_x][n_y] = true;
        DFS(n_x, n_y);
    }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                cnt_town_person = 1;
                cnt_town++;
                visited[i][j] = true;
                DFS(i, j);
                cnt_town_people.push_back(cnt_town_person);
            }
        }
    }

    sort(cnt_town_people.begin(), cnt_town_people.end());

    cout << cnt_town << '\n';

    for (int i = 0; i < cnt_town_people.size(); i++) {
        cout << cnt_town_people[i] << '\n';
    }
}