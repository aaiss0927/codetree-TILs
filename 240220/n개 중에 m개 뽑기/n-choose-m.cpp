#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> v;

void choose(int cur, int next) {
    if (cur == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = next; i <= n; i++) {
        v.push_back(i);
        choose(cur + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    choose(0, 1);
}