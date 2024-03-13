#include <iostream>
#include <set>
using namespace std;

int n, m;
set<pair<int, int>> s;

int main() {
	cin >> n >> m;

	while (n--) {
		int x, y; cin >> x >> y;
		s.insert({ x, y });
	}

	while (m--) {
		int x, y; cin >> x >> y;

		if (s.lower_bound({ x, y }) != s.end()) {
			cout << s.lower_bound({ x, y })->first << ' ' << s.lower_bound({ x, y })->second << '\n';
		}

		else {
			cout << "-1 -1\n";
		}
	}
}