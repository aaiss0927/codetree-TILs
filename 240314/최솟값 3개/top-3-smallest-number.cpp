#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	cin >> n;

	while (n--) {
		long long num; cin >> num;
		pq.push(num);

		if (pq.size() < 3) {
			cout << "-1\n";
			continue;
		}

		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		long long c = pq.top();
		pq.push(a); pq.push(b);

		long long ans = a * b * c;
		cout << ans << '\n';
	}
}