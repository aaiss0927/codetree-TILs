#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;
bool visited[1000001] = {false, };
int step[1000001] = {0, };

int op(int num, int i) {
    if (i == 0) {
        return num / 3;
    }

    else if (i == 1) {
        return num / 2;
    }

    else if (i == 2) {
        return num - 1;
    }

    else if (i == 3) {
        return num + 1;
    }
}

bool can_do(int num, int i) {
    return ((i == 2 || i == 3) || (i == 1 && (num % 2 == 0)) || (i == 0 && (num % 3 == 0)));
}

void BFS() {

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (can_do(num, i)) {
                int n_num = op(num, i);

                if (!visited[n_num]) {
                    visited[n_num] = true;
                    step[n_num] = step[num] + 1;
                    q.push(n_num);

                    if (n_num == 1) {
                        cout << step[n_num];
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    visited[n] = true;
    step[n] = 0;
    q.push(n);
    BFS();
}