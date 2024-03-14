#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		set<int>::iterator it = s.upper_bound(num);

		if (*it == *s.begin()) {
			cout << "-1\n";
			continue;
		}

		cout << *(--it) << '\n';
		s.erase(it);
	}
}