#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> answer;

void choose(int cur) {
    if (cur >= n) {
        for (int a : answer)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= k; i++) {
        answer.push_back(i);
        choose(cur + 1);
        answer.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    choose(0);
}