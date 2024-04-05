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
		map[v[i]]--;

		for (int j = 0; j < i; j++) {
			int target = k - v[i] - v[j];

			if (map.find(target) != map.end()) {
				cnt += map[target];
			}
		}
	}

	cout << cnt;
}