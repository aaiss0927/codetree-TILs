#include <iostream>
#include <vector>
using namespace std;

int n;

bool check_series(vector<int> temp) {
    int sz = temp.size();

    for (int i = 1; i <= (sz / 2); i++) {
        for (int j = i; j < sz; j++) {
            if (j + i <= sz) {
                vector<int> one(i);
                vector<int> two(i);

                copy(temp.begin() + j - i, temp.begin() + j, one.begin());
                copy(temp.begin() + j, temp.begin() + j + i, two.begin());

                if (one == two) {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<int> v;
bool is_finish = false;

void make_series(int cnt) {
    if (cnt == n) {
        if (!is_finish) {
            is_finish = true;

            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
            }
        }
        return;
    }

    for (int i = 4; i <= 6; i++) {
        if (!v.empty() && v.back() == i) {
            continue;
        }

        v.push_back(i);
        if (check_series(v)) {
            make_series(cnt + 1);
        }
        v.pop_back();
    }
}

int main() {
    cin >> n;

    make_series(0);
}