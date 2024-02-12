#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void choose(int cur_num) {
	if (cur_num == n + 1) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= k; i++) {
		v.push_back(i);
		choose(cur_num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> k >> n;
	choose(1);
}