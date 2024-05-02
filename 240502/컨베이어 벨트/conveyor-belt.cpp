#include <iostream>
#include <queue>
using namespace std;

int n, t;

int main() {
	cin >> n >> t;
	vector<int> V_1, V_2;
	queue<int> Q_1, Q_2;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		V_1.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		V_2.push_back(num);
	}

	for (int i = n - 1; i >= 0; i--) {
		Q_1.push(V_1[i]);
		Q_2.push(V_2[i]);
	}
	V_1.clear();
	V_2.clear();

	while (t--) {
		int temp = Q_1.front();
		Q_1.pop();
		Q_1.push(Q_2.front());
		Q_2.pop();
		Q_2.push(temp);
	}

	for (int i = 0; i < n; i++) {
		V_1.push_back(Q_1.front());
		Q_1.pop();
		V_2.push_back(Q_2.front());
		Q_2.pop();
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << V_1[i] << " ";
	}
	cout << '\n';
	for (int i = n - 1; i >= 0; i--) {
		cout << V_2[i] << " ";
	}
}