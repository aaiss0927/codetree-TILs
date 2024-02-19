#include <iostream>
#include <vector>
using namespace std;

int n;

bool check_series(vector<int> temp) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;

            for (int k = 0; k < i; k++) {
                if (j + k < n) {
                    if (temp[j + k] == temp[j + k - i]) {
                        cnt++;
                    }
                }
            }

            if (cnt == i) {
                return false;
            }
        }
    }

    return true;
}

vector<int> v;
bool is_finish = false;

void make_series(int cnt) {
    if (cnt == n) {
        if (!is_finish && check_series(v)) {
            is_finish = true;

            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
            }
        }
        return;
    }

    for (int i = 4; i <= 6; i++) {
        v.push_back(i);
        make_series(cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n;

    make_series(0);
}