#include <iostream>
using namespace std;

int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dir;
int grid[100][100];

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool is_comf(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (in_range(nx, ny) && grid[nx][ny] == 1) {
			cnt++;
		}
	}

	return (cnt == 3);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m; cin >> n >> m;

	while (m--) {
		int r, c; cin >> r >> c; r--; c--;
		grid[r][c] = 1;

		cout << is_comf(r, c) << '\n';
	}
}