#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> s;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;

		if (s.find(num) != s.end()) {
			cout << "1 ";
		}

		else {
			cout << "0 ";
		}
	}
}