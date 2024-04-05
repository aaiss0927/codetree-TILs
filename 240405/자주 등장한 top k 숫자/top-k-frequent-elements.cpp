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

	while (k--) {
		int max_count = 0;
		int max_elemt = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (map[v[i]] > max_count) {
				max_count = map[v[i]];
				max_elemt = v[i];
			}
		}

		map[max_elemt] = -1;
		cout << max_elemt << " ";
	}
}