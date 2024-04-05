#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) {
		return true;
	}

	else if (a.second == b.second) {
		if (a.first < b.first) {
			return true;
		}

		else {
			return false;
		}
	}

	else {
		return false;
	}
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]]++;
	}

	vector<pair<int, int>> temp(map.begin(), map.end());
	sort(temp.begin(), temp.end(), cmp);

	for (int i = (int)temp.size() - 1; i >= (int)temp.size() - k; i--) {
		cout << temp[i].first << " ";
	}
}