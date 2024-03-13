#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> mp;

int main() {
	cin >> n;

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int k, v; cin >> k >> v;
			mp[k] = v;
		}

		else if (cmd == "remove") {
			int k; cin >> k;
			mp.erase(k);
		}

		else if (cmd == "find") {
			int k; cin >> k;

			if (mp.find(k) != mp.end()) {
				cout << mp[k] << '\n';
			}

			else {
				cout << "None\n";
			}
		}

		else if (cmd == "print_list") {
			if (mp.empty()) {
				cout << "None\n";
			}

			else {
				for (auto it = mp.begin(); it != mp.end(); it++) {
					cout << it->second << ' ';
				}
				cout << '\n';
			}
		}
	}
}