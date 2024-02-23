#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
int ans = 1;

bool is_asc(vector<int> v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) {
            return false;
        }
    }

    return true;
}

vector<int> v;
vector<int> new_arr;

bool flag_finish;

void choose(int cnt, int next) {
    if (flag_finish) {
        return;
    }

    if (v.size() == cnt) {
        new_arr.clear();

        for (int i = 0; i < cnt; i++) {
            new_arr.push_back(arr[v[i]]);
        }

        if (is_asc(new_arr)) {
            ans = cnt;
            flag_finish = true;
        }

        return;
    }

    for (int i = next; i < n; i++) {
        v.push_back(i);
        choose(cnt, i + 1);
        v.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }

    for (int i = 2; i <= n; i++) {
        v.clear();
        new_arr.clear();
        flag_finish = false;
        choose(i, 0);
    }

    cout << ans;
}