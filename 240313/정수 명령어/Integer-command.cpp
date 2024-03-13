#include <iostream>
#include <set>
using namespace std;

int T;

int main() {
	cin >> T;

	while (T--) {
		set<int> s;
		int k; cin >> k;

		while (k--) {
			char cmd; cin >> cmd;

			if (cmd == 'I') {
				int n; cin >> n;
				s.insert(n);
			}

			else if (cmd == 'D') {
				int num; cin >> num;

				if (s.empty()) {
					continue;
				}

				if (num == 1) {
					s.erase(*s.rbegin());
				}

				else if (num == -1) {
					s.erase(*s.begin());
				}
			}
		}

		if (s.empty()) {
			cout << "EMPTY\n";
		}

		else {
			cout << *s.rbegin() << ' ' << *s.begin() << '\n';
		}
	}
}