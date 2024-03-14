#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int n;
set<int> s;

int main() {
	cin >> n;

	s.insert(0);

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);

		int sht = INT_MAX;

		for (auto it = s.begin(); it != s.end(); it++) {
			if (*it == *s.rbegin()) {
				continue;
			}

			int first = *it++;
			int second = *it--;
			sht = min(second - first, sht);
		}

		cout << sht << '\n';
	}
}