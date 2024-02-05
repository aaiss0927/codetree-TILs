#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[100][100];



void explosion(int r, int c) {	
	int num = grid[r][c] - 1;
	
	int s_r = r - num;
	if (s_r < 0) {
		s_r = 0;
	}
	
	int e_r = r + num;
	if (e_r >= n) {
		e_r = n - 1;
	}

	int s_c = c - num;
	if (s_c < 0) {
		s_c = 0;
	}

	int e_c = c + num;
	if (e_c >= n) {
		e_c = n - 1;
	}

	for (int i = s_r; i <= e_r; i++) {
		grid[i][c] = 0;
	}

	for (int j = s_c; j <= e_c; j++) {
		grid[r][j] = 0;
	}

	for (int j = s_c; j <= e_c; j++) {
		vector<int> v;
		int num_zero = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (grid[i][j] != 0) {
				v.push_back(grid[i][j]);
			}
			else {
				num_zero++;
			}
		}
		for (int i = 0; i < num_zero; i++) {
			v.push_back(0);
		}

		for (int i = n - 1; i >= 0; i--) {
			grid[i][j] = v[n - 1 - i];
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	while (m--) {
		int c; cin >> c;
		c--;
		int r;
		bool check_row = false;

		for (int i = 0; i < n; i++) {
			if (grid[i][c] != 0) {
				r = i;
				check_row = true;
				break;
			}
		}

		if (!check_row) {
			break;
		}

		explosion(r, c);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}