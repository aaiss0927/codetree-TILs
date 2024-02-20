#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <map>
#include <cmath>
using namespace std;

int n;
char grid[20][20];

pair<int, int> start_pnt, end_pnt;
map<int, pair<int, int>> coins;
// <num, {x, y}>
vector<int> coin_nums;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int ans = INT_MAX;

bool is_num(char c) {
    if (c != '.' && c != 'S' && c != 'E') {
        return true;
    }

    return false;
}

int get_distance(pair<int, int> pnt1, pair<int, int> pnt2) {
    return (abs(pnt1.first - pnt2.first) + abs(pnt1.second - pnt2.second));
}

vector<int> idx;
// ex) coin_nums = {7, 8, 9} 
void process(int cur, int next, int selected_num) {
    if (cur == selected_num) {
        int distance = get_distance(start_pnt, coins[coin_nums[idx[0]]]);
        pair<int, int> temp;

        for (int i = 0; i < selected_num - 1; i++) {
            distance += get_distance(coins[coin_nums[idx[i]]], coins[coin_nums[idx[i + 1]]]);
            if (i == selected_num - 2) {
                temp = coins[coin_nums[idx[i + 1]]];
            }
        }

        distance += get_distance(temp, end_pnt);

        ans = min(ans, distance);
        return;
    }

    for (int i = next; i < coin_nums.size(); i++) {
        idx.push_back(i);
        process(cur + 1, i + 1, selected_num);
        idx.pop_back();
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
            if (grid[i][j] == 'S') {
                start_pnt = { i, j };
            }

            if (grid[i][j] == 'E') {
                end_pnt = { i, j };
            }

            if (is_num(grid[i][j])) {
                coins.insert({ grid[i][j] - '0', {i, j} });
            }
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (coins.find(i) != coins.end()) {
            coin_nums.push_back(i);
        }
    }

    if (coin_nums.size() < 3) {
        cout << -1;
        return 0;
    }

    for (int i = 3; i <= coin_nums.size(); i++) {
        process(0, 0, i);
    }

    cout << ans;
}