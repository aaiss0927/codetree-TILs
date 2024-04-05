#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
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
	vector<long long> v(n);
	unordered_map<long long, long long> map;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]]++;
	}

	vector<pair<long long, long long>> temp(map.begin(), map.end());
	sort(temp.begin(), temp.end(), cmp);

	for (int i = temp.size() - 1; i >= temp.size() - k; i--) {
		cout << temp[i].first << " ";
	}
}