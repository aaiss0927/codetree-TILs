#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<int> pq;

int main() {
	cin >> n >> m;

	while (n--) {
		int num; cin >> num;
		pq.push(num);
	}

	while (m--) {
		int temp = pq.top(); pq.pop();
		temp--; pq.push(temp);
	}

	cout << pq.top();
}