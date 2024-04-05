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
	}

	int cnt = 0;

	for (int i = 2; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			int target = k - v[i] - v[j];

			if (map.find(target) != map.end()) {
				cnt += map[target];
			}
		}

		map[v[i]]++;
	}

	cout << cnt;
}