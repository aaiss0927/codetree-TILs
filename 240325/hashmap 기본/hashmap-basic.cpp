#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> m;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int k, v; cin >> k >> v;
			m[k] = v;
		}

		else if (cmd == "remove") {
			int k; cin >> k;
			m.erase(k);
		}

		else if (cmd == "find") {
			int k; cin >> k;

			if (m.find(k) == m.end()) {
				cout << "None\n";
			}

			else {
				cout << m.find(k)->second << '\n';
			}
		}
	}
}