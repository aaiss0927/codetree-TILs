#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

pair<int, int> rotate_1(pair<int, int> dir) {
	if (dir.first == 0 && dir.second == 1) {
		return { -1, 0 };
	}

	else if (dir.first == -1 && dir.second == 0) {
		return { 0, 1 };
	}

	else if (dir.first == 0 && dir.second == -1) {
		return { 1, 0 };
	}

	else if (dir.first == 1 && dir.second == 0) {
		return { 0, -1 };
	}
}

pair<int, int> rotate_2(pair<int, int> dir) {
	if (dir.first == 0 && dir.second == 1) {
		return { 1, 0 };
	}

	else if (dir.first == -1 && dir.second == 0) {
		return { 0, -1 };
	}

	else if (dir.first == 0 && dir.second == -1) {
		return { -1, 0 };
	}

	else if (dir.first == 1 && dir.second == 0) {
		return { 0, 1 };
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int c_x, c_y;
	pair<int, int> cur_dir;
	vector<int> times;

	for (int i = 0; i < n; i++) {
		c_x = i; c_y = 0;
		cur_dir = { 0, 1 };

		int t = 1;

		while (is_range(c_x, c_y)) {
			t++;

			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (!is_range(c_x, c_y)) {
				break;
			}

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}
		}

		times.push_back(t);
	}

	for (int j = 0; j < n; j++) {
		c_x = n - 1; c_y = j;
		cur_dir = { -1, 0 };

		int t = 1;

		while (is_range(c_x, c_y)) {
			t++;

			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (!is_range(c_x, c_y)) {
				break;
			}

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}
		}

		times.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		c_x = i; c_y = n - 1;
		cur_dir = { 0, -1 };

		int t = 1;

		while (is_range(c_x, c_y)) {
			t++;
			
			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (!is_range(c_x, c_y)) {
				break;
			}

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}
		}

		times.push_back(t);
	}

	for (int j = 0; j < n; j++) {
		c_x = 0; c_y = j;
		cur_dir = { 1, 0 };

		int t = 1;

		while (is_range(c_x, c_y)) {
			t++;

			int n_x = c_x + cur_dir.first;
			int n_y = c_y + cur_dir.second;

			c_x = n_x;
			c_y = n_y;

			if (!is_range(c_x, c_y)) {
				break;
			}

			if (grid[c_x][c_y] == 1) {
				cur_dir = rotate_1(cur_dir);
			}

			else if (grid[c_x][c_y] == 2) {
				cur_dir = rotate_2(cur_dir);
			}
		}

		times.push_back(t);
	}

	sort(times.begin(), times.end());

	cout << times.back();
}