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
	int sht = INT_MAX;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);

		set<int>::iterator it = s.find(num);
		
		int cand_1 = num - *(--it); ++it;

		if (*it == *s.rbegin()) {
			sht = min(sht, cand_1);
			cout << sht << '\n';
			continue;
		}

		int cand_2 = *(++it) - num; --it;

		sht = min(sht, min(cand_1, cand_2));
		cout << sht << '\n';
	}
}