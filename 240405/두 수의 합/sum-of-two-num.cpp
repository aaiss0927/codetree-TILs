#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v;
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
		map[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[j] == k - v[i]) {
				map[i]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += map[i];
	}

	cout << cnt;
}