#include <iostream>
#include <vector>
using namespace std;

int k, n;

vector<int> v;

bool is_valid(vector<int> temp) {
    int cont = 1;
    
    for (int i = 1; i < temp.size(); i++) {
        if (temp[i] == temp[i - 1]) {
            cont++;
        }

        else {
            cont = 1;
        }

        if (cont == 3) {
            return false;
        }
    }

    return true;
}

void choose(int cnt) {
    if (cnt == n) {
        if (is_valid(v)) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= k; i++) {
        v.push_back(i);
        choose(cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> k >> n;

    choose(0);
}