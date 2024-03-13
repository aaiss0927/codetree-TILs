#include <iostream>
#include <set>
using namespace std;

int n;
set<int> s;

int main() {
	cin >> n;

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int x; cin >> x;
			s.insert(x);
		}

		else if (cmd == "remove") {
			int x; cin >> x;
			s.erase(x);
		}

		else if (cmd == "find") {
			int x; cin >> x;

			if (s.find(x) != s.end()) {
				cout << "true\n";
			}

			else {
				cout << "false\n";
			}
		}

		else if (cmd == "lower_bound") {
			int x; cin >> x;
			
			if (s.lower_bound(x) == s.end()) {
				cout << "None\n";
			}

			else {
				cout << *s.lower_bound(x) << '\n';
			}
		}

		else if (cmd == "upper_bound") {
			int x; cin >> x;

			if (s.upper_bound(x) == s.end()) {
				cout << "None\n";
			}

			else {
				cout << *s.upper_bound(x) << '\n';
			}
		}

		else if (cmd == "largest") {
			if (s.empty()) {
				cout << "None\n";
			}

			else {
				cout << *s.rbegin() << '\n';
			}
		}

		else if (cmd == "smallest") {
			if (s.empty()) {
				cout << "None\n";
			}

			else {
				cout << *s.begin() << '\n';
			}
		}
	}
}