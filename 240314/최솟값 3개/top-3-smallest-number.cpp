#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;

	while (n--) {
		int num; cin >> num;
		pq.push(num);

		if (pq.size() < 3) {
			cout << "-1\n";
			continue;
		}

		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int c = pq.top();
		pq.push(a); pq.push(b);

		cout << a * b * c << '\n';
	}
}