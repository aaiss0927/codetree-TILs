#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long, long> mp;

int main() {
	cin >> n;

	while (n--) {
		long x, y; cin >> x >> y;

		if (mp.find(x) != mp.end()) {
			if (y < mp[x]) {
				mp[x] = y;
			}
		}

		else {
			mp[x] = y;
		}
	}

	long ans = 0;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans += it->second;
	}

	cout << ans;
}