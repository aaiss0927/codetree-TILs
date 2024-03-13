#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> mp;

int main() {
	cin >> n;

	while (n--) {
		string str; cin >> str;
		mp[str]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << ' ' << it->second << '\n';
	}
}