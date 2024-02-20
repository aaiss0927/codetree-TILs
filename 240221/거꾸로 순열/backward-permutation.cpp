#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<bool> visited(n + 1, false);

void perm(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        v.push_back(i);
        perm(cur + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    perm(0);
}