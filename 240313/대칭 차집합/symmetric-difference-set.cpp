#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		
		if (s.find(num) != s.end()) {
			cnt++;
		}
	}

	cout << n + m - 2 * cnt;
}