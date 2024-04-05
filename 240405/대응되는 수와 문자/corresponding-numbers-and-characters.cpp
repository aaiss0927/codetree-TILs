#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	unordered_map<string, int> map_1;
	unordered_map<int, string> map_2;

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		map_1[s] = i;
		map_2[i] = s;
	}

	while (m--) {
		string s; cin >> s;

		if (isdigit(s[0])) {
			cout << map_2[stoi(s)] << '\n';
		}

		else {
			cout << map_1[s] << '\n';
		}
	}
}