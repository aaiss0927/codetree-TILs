#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, c;
int grid[10][10];

vector<vector<int>> all_case;
vector<int> one_case;

int ans;

void choose(int cnt, int next) {
    if (cnt == 2) {
        if ((one_case[0] % n) <= (n - m) && (one_case[1] % n) <= (n - m)) {
            if ((one_case[0] / n) != (one_case[1] / n)) {
                all_case.push_back(one_case);
            }

            else {
                if (abs(one_case[0] - one_case[1]) >= m) {
                    all_case.push_back(one_case);
                }
            }
        }

        return;
    }

    for (int i = next; i < pow(n, 2); i++) {
        one_case.push_back(i);
        choose(cnt + 1, i + 1);
        one_case.pop_back();
    }
}


vector<vector<int>> subsets;
vector<int> subset;

void get_able(int cnt, int cur_num) {
    if (cnt == m) {
        int sum = 0;

        for (int i = 0; i < subset.size(); i++) {
            sum += grid[(cur_num + subset[i]) / n][(cur_num + subset[i]) % n];
        }

        if (sum <= c) {
            subsets.push_back(subset);
        }

        return;
    }

    get_able(cnt + 1, cur_num);
    subset.push_back(cnt);
    get_able(cnt + 1, cur_num);
    subset.pop_back();
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    choose(0, 0);

    for (auto it = all_case.begin(); it != all_case.end(); it++) {
        int value = 0;

        for (int i = 0; i < 2; i++) {
            int sum = 0;

            for (int j = 0; j < m; j++) {
                sum += grid[((*it)[i] + j) / n][((*it)[i] + j) % n];
            }

            if (sum <= c) {
                for (int j = 0; j < m; j++) {
                    value += pow(grid[((*it)[i] + j) / n][((*it)[i] + j) % n], 2);
                }
            }

            else {
                subsets.clear();
                get_able(0, ((*it)[i]));

                int max_temp = 0;
                for (int j = 0; j < subsets.size(); j++) {
                    int temp = 0;
                    
                    for (int k = 0; k < subsets[j].size(); k++) {
                        temp += pow(grid[((*it)[i] + subsets[j][k]) / n][((*it)[i] + subsets[j][k]) % n], 2);
                    }

                    max_temp = max(temp, max_temp);
                }

                value += max_temp;
            }

            ans = max(value, ans);
        }
    }

    cout << ans;
}