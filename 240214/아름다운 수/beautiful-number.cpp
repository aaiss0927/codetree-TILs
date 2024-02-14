#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<int> arr;
vector<vector<int>> candidate;

void make_candidate() {
	if (arr.size() == n) {
		candidate.push_back(arr);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		arr.push_back(i);
		make_candidate();
		arr.pop_back();
	}
}

void process(int* cont) {
	for (int i = 0; i < 4; i++) {
		*(cont + i) = *(cont + i) % (i + 1);
	}
}

bool is_beautiful(int* cont) {
	for (int i = 0; i < 4; i++) {
		if (*(cont + i) != 0) {
			return false;
		}
	}

	return true;
}

void num_beautiful_num() {
	for (auto it = candidate.begin(); it != candidate.end(); it++) {
		int cont[4] = { 0, };
		int cur_num = (*it)[0];
		cont[cur_num - 1]++;
		process(cont);
		
		for (int i = 1; i < n; i++) {
			if ((*it)[i] == (*it)[i - 1]) {
				cont[cur_num - 1]++;
				process(cont);
			}
			else {
				if (!is_beautiful(cont)) {
					break;
				}
				cur_num = (*it)[i];
				cont[cur_num - 1]++;
			}
		}

		process(cont);

		if (!is_beautiful(cont)) {
			continue;
		}

		ans++;
	}
}

int main() {
	cin >> n;

	make_candidate();
	num_beautiful_num();
	cout << ans;
}