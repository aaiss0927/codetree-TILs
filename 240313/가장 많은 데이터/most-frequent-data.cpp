#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
unordered_map<string, int> map;

int main() {
	cin >> n;

	while (n--) {
		string str; cin >> str;
		map[str]++;
	}

	int ans = 0;

	for (auto it = map.begin(); it != map.end(); it++) {
		ans = max(ans, it->second);
	}

	cout << ans;
}