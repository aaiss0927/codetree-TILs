#include <iostream>
#include <vector>
using namespace std;

vector<int> algorithm(vector<int> v, int s, int e) {
	vector<int> temp;
	for (int i = 0; i < v.size(); i++) {
		if (i >= s && i <= e) {
			continue;
		}
		temp.push_back(v[i]);
	}
	return temp;
}

int main() {
	int n; cin >> n;
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}

	int s_1, e_1, s_2, e_2;
	cin >> s_1 >> e_1 >> s_2 >> e_2;
	s_1--; e_1--; s_2--; e_2--;

	
	arr = algorithm(arr, s_1, e_1);
	arr = algorithm(arr, s_2, e_2);

	cout << arr.size() << '\n';
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}
}