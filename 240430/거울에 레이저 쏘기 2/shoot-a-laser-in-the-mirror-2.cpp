#include <iostream>
#include <tuple>
using namespace std;

int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dir;
char grid[1000][1000];

tuple<int, int, int> get_start_status(int k) {
	int x, y, dir;

	if (k < n) {
		dir = 2;
		x = -1;
		y = k;
	}

	else if (k < 2 * n) {
		dir = 1;
		x = k % n;
		y = n;
	}

	else if (k < 3 * n) {
		dir = 0;
		x = n;
		y = (n - 1) - (k % n);
	}

	else {
		dir = 3;
		x = (n - 1) - (k % n);
		y = -1;
	}

	return { x, y, dir };
}

int set_dir(int dir, char c) {
	int ndir = 0;

	if (dir == 0) {
		if (c == '/') {
			ndir = 3;
		}

		else {
			ndir = 1;
		}
	}

	else if (dir == 1) {
		if (c == '/') {
			ndir = 2;
		}

		else {
			ndir = 0;
		}
	}

	else if (dir == 2) {
		if (c == '/') {
			ndir = 1;
		}

		else {
			ndir = 3;
		}
	}

	else if (dir == 3) {
		if (c == '/') {
			ndir = 0;
		}

		else {
			ndir = 2;
		}
	}

	return ndir;
}

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int k; cin >> k;
	int x, y;
	tie(x, y, dir) = get_start_status(k - 1);
	int cnt = 0;

	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!in_range(nx, ny)) {
			cout << cnt;
			return 0;
		}

		x = nx; y = ny;
		dir = set_dir(dir, grid[nx][ny]);
		cnt++;
	}
}