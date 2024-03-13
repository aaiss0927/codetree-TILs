#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int n;
map<string, int> mp;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		
		mp[str]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << ' ' << fixed << setprecision(4) << (double(it->second) / n) * 100 << '\n';
	}
}