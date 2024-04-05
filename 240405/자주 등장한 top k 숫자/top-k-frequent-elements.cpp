#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]]++;
	}

	vector<pair<int, int>> temp;

	for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
		temp.push_back({ it->second, it->first });
	}

	sort(temp.begin(), temp.end());

	for (int i = temp.size() - 1; i >= temp.size() - k; i--) {
		cout << temp[i].second << " ";
	}
}