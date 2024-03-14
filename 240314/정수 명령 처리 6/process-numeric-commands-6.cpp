#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
	cin >> n;

	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "push") {
			int a; cin >> a;
			pq.push(a);
		}

		else if (cmd == "pop") {
			cout << pq.top() << '\n';
			pq.pop();
		}

		else if (cmd == "size") {
			cout << pq.size() << '\n';
		}

		else if (cmd == "empty") {
			cout << pq.empty() << '\n';
		}

		else if (cmd == "top") {
			cout << pq.top() << '\n';
		}
	}
}