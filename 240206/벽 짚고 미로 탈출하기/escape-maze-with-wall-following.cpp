#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, x, y;

int dx[4] = { 0, -1, 0, 1 };

int dy[4] = { 1, 0, -1, 0 };

vector<pair<int, int>> dirs;

char grid[100][100];

bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

bool is_right_wall(int x, int y, int idx) {
	int y_wall = y + dirs[idx].second;
	idx--;
	idx = (idx + 4) % 4;
	int x_wall = x + dirs[idx].first;
	return (grid[x_wall][y_wall] == '#');
}

void inc_idx(int& idx) {
	idx++;
	idx %= 4;
}

void dec_idx(int& idx) {
	idx--;
	idx = (idx + 4) % 4;
}

int main() {
	cin >> n >> x >> y;
	x--; y--;
	dirs = { {dx[0], dy[0]}, {dx[1], dy[1]}, {dx[2], dy[2]}, {dx[3], dy[3]} };
	int t = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int c_x = x;
	int c_y = y;
	int idx = 0;
	pair<int, int> cur_dir = dirs[idx];
	int rotate_num_per_loop = 0;
	bool flag_first_loop = true;

	while (true) {		
		int n_x = c_x + cur_dir.first;
		int n_y = c_y + cur_dir.second;

		if (rotate_num_per_loop == 4) {
			cout << -1;
			return 0;
		}

		if (c_x == x && c_y == y && idx == 0 && !flag_first_loop) {
			cout << -1;
			return 0;
		}

		if (grid[n_x][n_y] == '#') {
			inc_idx(idx);
			cur_dir = dirs[idx];
			rotate_num_per_loop++;
			flag_first_loop = false;
			continue;
		}

		rotate_num_per_loop = 0;

		if (!is_range(n_x, n_y)) {
			t++;
			flag_first_loop = false;
			break;
		}

		if (is_range(n_x, n_y) && is_right_wall(c_x, c_y, idx)) {
			t++;
			c_x = n_x;
			c_y = n_y;
			flag_first_loop = false;
			continue;
		}

		if (is_range(n_x, n_y) && !is_right_wall(c_x, c_y, idx)) {
			t += 2;
			c_x = n_x + cur_dir.first;
			c_y = n_y + cur_dir.second;
			dec_idx(idx);
			cur_dir = dirs[idx];
			c_x = n_x + cur_dir.first;
			c_y = n_y + cur_dir.second;
			flag_first_loop = false;
			continue;
		}
	}

	cout << t;
}