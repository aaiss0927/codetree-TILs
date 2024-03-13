#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;

int main() {
	cin >> n >> m;

	while (n--) {
		int num; cin >> num;
		s.insert(num);
	}

	while (m--) {
		int num; cin >> num;

		if (s.lower_bound(num) == s.end()) {
			cout << "-1\n";
		}

		else {
			cout << *s.lower_bound(num) << '\n';
		}
	}
}