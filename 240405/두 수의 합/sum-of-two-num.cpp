#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]]++;
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int target = k - v[i];

		if (map.find(target) != map.end()) {
			cnt += map[target];
			map[v[i]]--;
		}
	}

	cout << cnt;
}