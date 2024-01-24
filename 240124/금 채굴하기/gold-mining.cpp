#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int grid[20][20];

bool check(int row, int col) {
	return (row >= 0 && row < n && col >= 0 && col < n);
}

int find_gold(int row, int col, int k) {
	int num = 0;

	if (grid[row][col]) {
		num++;
	}

	for (int i = 1; i <= k; i++) {
		if (check(row - k, col)) {
			if (grid[row - k][col]) {
				num++;
			}
		}
		if (check(row, col + k)) {
			if (grid[row][col + k]) {
				num++;
			}
		}
		if (check(row + k, col)) {
			if (grid[row + k][col]) {
				num++;
			}
		}
		if (check(row, col - k)) {
			if (grid[row][col - k]) {
				num++;
			}
		}
	}

	return num;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int cost = pow(k, 2) + pow(k + 1, 2);
				int gold_num = find_gold(i, j, k);

				if (gold_num * m >= cost) {
					ans = max(ans, gold_num);
				}
			}
		}
	}
	
	cout << ans;
}