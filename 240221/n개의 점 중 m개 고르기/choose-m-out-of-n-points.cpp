#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> pnts;
// {{1, 1}, {4, 4}, {3, 5}}
int ans = INT_MAX;

int square_dist(pair<int, int> pnt1, pair<int, int> pnt2) {
    return (pow(pnt1.first - pnt2.first, 2) + pow(pnt1.second - pnt2.second, 2));
}

vector<int> v;
int dist;
vector<int> idxs;
// {0, 1, 2}

void select_2(int cur, int next, vector<int> temp) {
    if (cur == 2) {
        dist = max(dist, square_dist(pnts[temp[v[0]]], pnts[temp[v[1]]]));
        return;
    }

    for (int i = next; i < temp.size(); i++) {
        v.push_back(i);
        select_2(cur + 1, i + 1, temp);
        v.pop_back();
    }
}

// idxs = {0, 1}, {0, 2}, {1, 2}
void choose(int cur, int next) {
    if (cur == m) {
        dist = INT_MIN;
        select_2(0, 0, idxs);
        ans = min(ans, dist);
        return;
    }

    for (int i = next; i < n; i++) {
        idxs.push_back(i);
        choose(cur + 1, i + 1);
        idxs.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pnts.push_back({x, y});
    }

    choose(0, 0);

    cout << ans;
}