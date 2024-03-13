#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
int arr[100000];
unordered_map<int, int> map;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr[i] = num;
		
		if (map.find(arr[i]) == map.end()) {
			map[arr[i]] = 1;
		}

		else {
			map[arr[i]]++;
		}
	}

	while (m--) {
		int num; cin >> num;
		cout << map[num] << ' ';
	}
}