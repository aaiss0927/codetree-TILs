#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<int> target;
bool ladder[16][12];
// ladder[m][n];

vector<int> ladder_result(vector<pair<int, int>> input) {
	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ladder[j][i] = false;
		}
	}

	for (auto it = input.begin(); it != input.end(); it++) {
		ladder[it->second][it->first] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ladder[j][initial[i]]) {
				initial[i] = initial[i] + 1;
			}

			else if (ladder[j][initial[i] - 1]) {
				initial[i] = initial[i] - 1;
			}
		}
	}

	vector<int> result(n + 1);
	result[0] = 0;
	for (int i = 1; i <= n; i++) {
		result[initial[i]] = i;
	}

	return result;
}

bool is_equal(vector<int> v1, vector<int> v2) {
	for (int i = 1; i <= n; i++) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}

	return true;
}

bool is_wrong(vector<pair<int, int>> input) {
	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ladder[j][i] = false;
		}
	}

	for (auto it = input.begin(); it != input.end(); it++) {
		ladder[it->second][it->first] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (initial[i] > 1 && initial[i] < n) {
				if (ladder[j][initial[i]] && ladder[j][initial[i] - 1]) {
					return true;
				}
			}
		}
	}

	return false;
}

vector<vector<int>> all_case;
vector<int> one_case;

void get_all_case(int cnt, int line_num) {
	if (cnt == 2) {
		all_case.push_back(one_case);
		return;
	}

	if (cnt == 0) {
		for (int i = 1;  i <= n - 1;  i++) {
			one_case.push_back(i);
			get_all_case(cnt + 1, line_num);
			one_case.pop_back();
		}
	}	

	if (cnt == 1) {
		for (int i = 1; i <= line_num; i++) {
			one_case.push_back(i);
			get_all_case(cnt + 1, line_num);
			one_case.pop_back();
		}
	}
}

vector<vector<int>> my_input_idxs;
vector<int> one_input_idx;

void get_my_input_idx(int cnt, int line_num, vector<bool> is_it) {
	if (cnt == line_num) {
		my_input_idxs.push_back(one_input_idx);
		return;
	}

	for (int i = 0; i < all_case.size(); i++) {
		if (is_it[i]) {
			continue;
		}

		one_input_idx.push_back(i);
		is_it[i] = true;
		get_my_input_idx(cnt + 1, line_num, is_it);
		one_input_idx.pop_back();
		is_it[i] = false;
	}
}

int main() {
	cin >> n >> m;

	vector<pair<int, int>> input;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;

		input.push_back({ a, b });
	}

	target = ladder_result(input);

	vector<int> initial(n + 1);

	for (int i = 0; i <= n; i++) {
		initial[i] = i;
	}

	if (is_equal(target, initial)) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= 15; i++) {
		one_case.clear();
		all_case.clear();

		get_all_case(0, i);

		one_input_idx.clear();
		my_input_idxs.clear();

		vector<bool> is_it(all_case.size());
		for (auto it = is_it.begin(); it != is_it.end(); it++) {
			(*it) = false;
		}

		vector<pair<int, int>> my_input;

		get_my_input_idx(0, i, is_it);

		for (auto it = my_input_idxs.begin(); it != my_input_idxs.end(); it++) {
			for (int j = 0; j < i; j++) {
				my_input.push_back({ all_case[(*it)[j]][0], all_case[(*it)[j]][1] });
			}

			if (!is_wrong(my_input)) {
				vector<int> my_result = ladder_result(my_input);

				if (is_equal(target, my_result)) {
					cout << i;
					return 0;
				}
			}

			my_input.clear();
		}
	}
}