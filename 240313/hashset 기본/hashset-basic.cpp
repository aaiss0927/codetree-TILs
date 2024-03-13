#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> s;

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
	}
}