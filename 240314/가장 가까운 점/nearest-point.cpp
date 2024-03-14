#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (abs(a.first) + abs(a.second) > abs(b.first) + abs(b.second)) {
			return true;
		}

		else if (abs(a.first) + abs(a.second) == abs(b.first) + abs(b.second)) {
			if (abs(a.first) > abs(b.first)) {
				return true;
			}

			else if (abs(a.first) == abs(b.first)) {
				if (abs(a.second) > abs(b.second)) {
					return true;
				}

				else {
					return false;
				}
			}

			else {
				return false;
			}
		}

		else {
			return false;
		}
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
	cin >> n >> m;

	while (n--) {
		int x, y; cin >> x >> y;
		pq.push({ x, y });
	}

	while (m--) {
		pair<int, int> temp = pq.top(); pq.pop();
		temp.first += 2; temp.second += 2; pq.push(temp);
	}

	cout << pq.top().first << ' ' << pq.top().second;
}