#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	unordered_map<int, int> map;

	int n; cin >> n;

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int k, v; cin >> k >> v;

			map[k] = v;
		}

		else if (cmd == "remove") {
			int k; cin >> k;

			map.erase(k);
		}

		else if (cmd == "find") {
			int k; cin >> k;

			if (map.find(k) != map.end()) {
				cout << map[k] << '\n';
			}

			else {
				cout << "None\n";
			}
		}
	}
}