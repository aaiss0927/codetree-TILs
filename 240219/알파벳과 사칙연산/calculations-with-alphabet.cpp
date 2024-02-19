#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;

string expr;
// [idx] a = 0 b = 1 c = 2 d = 3 e = 4 f = 5

int alpha[6];
char op[3] = { '+', '-', '*' };
int ans = INT_MIN;

bool is_op(char c) {
    for (int i = 0; i < 3; i++) {
        if (c == op[i]) {
            return true;
        }
    }

    return false;
}

vector<vector<int>> all_case;
vector<int> one_case;

void set_alpha_value(int cnt) {
    if (cnt == 6) {
        all_case.push_back(one_case);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        one_case.push_back(i);
        set_alpha_value(cnt + 1);
        one_case.pop_back();
    }
}

int main() {
    cin >> expr;

    if (expr.size() == 1) {
        cout << 4;
        return 0;
    }

    set_alpha_value(0);

    for (auto it = all_case.begin(); it != all_case.end(); it++) {
        string expr_ = expr;

        for (int i = 0; i < 6; i++) {
            alpha[i] = (*it)[i];
        }

        vector<char> post_expr;
        stack<char> post_stack;

        for (int i = 0; i < expr_.size(); i++) {
            if (!is_op(expr_[i])) {
                expr_[i] = alpha[expr_[i] - 97] + '0';
            }
        }

        for (int i = 0; i < expr_.size(); i++) {
            if (!is_op(expr_[i])) {
                post_expr.push_back(expr_[i]);
            }
            else {
                if (post_stack.empty()) {
                    post_stack.push(expr_[i]);
                }

                else {
                    post_expr.push_back(post_stack.top());
                    post_stack.pop();
                    post_stack.push(expr_[i]);
                }
            }
        }

        post_expr.push_back(post_stack.top());
        post_stack.pop();

        stack<int> calc_stack;
        int result;

        for (int i = 0; i < post_expr.size(); i++) {
            if (!is_op(post_expr[i])) {
                calc_stack.push(post_expr[i] - '0');
            }

            else {
                int second = calc_stack.top(); calc_stack.pop();
                int first = calc_stack.top(); calc_stack.pop();

                if (post_expr[i] == '+') {
                    calc_stack.push(first + second);
                }

                else if (post_expr[i] == '-') {
                    calc_stack.push(first - second);
                }

                else if (post_expr[i] == '*') {
                    calc_stack.push(first * second);
                }
            }
        }

        result = calc_stack.top(); calc_stack.pop();

        ans = max(ans, result);
    }

    cout << ans;
}