#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<long long> v(n);
	unordered_map<long long, long long> map;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]]++;
	}

	while (k--) {
		long long max_count = 0;
		long long max_elemt = 0;

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