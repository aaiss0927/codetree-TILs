#include <iostream>
using namespace std;

int n, m, q;
int r;
char d;
int grid[100][100];

void L2R(int row) {
	int temp = grid[row][m - 1];
	for (int i = m - 1; i > 0; i--) {
		grid[row][i] = grid[row][i - 1];
	}
	grid[row][0] = temp;
}

void R2L(int row) {
	int temp = grid[row][0];
	for (int i = 0; i < m - 1; i++) {
		grid[row][i] = grid[row][i + 1];
	}
	grid[row][m - 1] = temp;
}

bool check_up_sp(int row) {
	if (row == 0) {
		return false;
	}

	for (int i = 0; i < m; i++) {
		if (grid[row][i] == grid[row - 1][i]) {
			return true;
		}
	}

	return false;
}

bool check_down_sp(int row) {
	if (row == n) {
		return false;
	}

	for (int i = 0; i < m; i++) {
		if (grid[row][i] == grid[row - 1][i]) {
			return true;
		}
	}

	return false;
}

bool flag;

void up_algorithm(int row_, bool flag_) {
	if (flag_) {
		L2R(row_);
	}
	else {
		R2L(row_);
	}

	if (check_up_sp(row_)) {
		up_algorithm(row_ - 1, !flag_);
	}
}

void down_algorithm(int row_, bool flag_) {
	if (flag_) {
		L2R(row_);
	}
	else {
		R2L(row_);
	}

	if (check_down_sp(row_)) {
		down_algorithm(row_ + 1, !flag_);
	}
}

int main() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (q--) {
		cin >> r >> d;

		if (d == 'L') {
			flag = true;
		}
		else if (d == 'R') {
			flag = false;
		}

		up_algorithm(r - 1, flag);
		down_algorithm(r, !flag);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}