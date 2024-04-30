#include <iostream>
using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dir;

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int r, c; r = c = 0;

	int temp = n * m - 1;
	int num = 1;
	grid[r][c] = num;
	visited[r][c] = true;
	num++;

	while (temp--) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];

		if (!in_range(nx, ny) || visited[nx][ny]) {
			dir++;
			if (dir >= 4)
				dir -= 4;

			nx = r + dx[dir];
			ny = c + dy[dir];
		}

		r = nx; c = ny;
		grid[r][c] = num;
		visited[r][c] = true;
		num++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}