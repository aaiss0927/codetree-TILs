#include <iostream>
using namespace std;

int n;
int grid[99][99];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dir;

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> n >> t;
	string str; cin >> str;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int r, c; r = c = n / 2;
	int sum = grid[r][c];

	for (int i = 0; i < t; i++) {
		if (str[i] == 'L') {
			dir--;
			if (dir < 0)
				dir += 4;
		}

		else if (str[i] == 'R') {
			dir++;
			if (dir >= 4)
				dir -= 4;
		}

		else if (str[i] == 'F') {
			int nx = r + dx[dir];
			int ny = c + dy[dir];

			if (in_range(nx, ny)) {
				r = nx; c = ny;
				sum += grid[r][c];
			}
		}
	}

	cout << sum;
}