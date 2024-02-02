#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];
bool to_delete[100][100];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int r, c;
	cin >> r >> c;
	r--; c--;

	int num = grid[r][c] - 1;
	
	for (int i = r - num; i <= r + num; i++) {
		to_delete[i][c] = true;
	}

	for (int j = c - num; j <= c + num; j++) {
		to_delete[r][j] = true;
	}

	vector<vector<int>> temp;

	for (int j = c - num; j <= c + num; j++) {
		vector<int> v;
		int num_zero = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (to_delete[i][j]) {
				num_zero++;
			}
			else {
				v.push_back(grid[i][j]);
			}
		}

		for (int i = 0; i < num_zero; i++) {
			v.push_back(0);
		}

		temp.push_back(v);
	}

	int idx = 0;
	for (int j = c - num; j <= c + num; j++) {
		for (int i = n - 1; i >= 0; i--) {
			grid[i][j] = temp[idx][n - 1 - i];
		}

		idx++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}