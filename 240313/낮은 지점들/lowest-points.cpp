#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> map;

int main() {
	cin >> n;

	while (n--) {
		int x, y; cin >> x >> y;

		if (map.find(x) != map.end()) {
			if (y < map[x]) {
				map[x] = y;
			}
		}

		else {
			map[x] = y;
		}
	}

	int ans = 0;

	for (auto it = map.begin(); it != map.end(); it++) {
		ans += it->second;
	}

	cout << ans;
}