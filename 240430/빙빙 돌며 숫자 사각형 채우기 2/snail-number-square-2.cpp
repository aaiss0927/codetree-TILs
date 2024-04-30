#include <iostream>
#include <tuple>
using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dir;
int grid[100][100];
bool visited[100][100];

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int x, y; x = y = 0;

	int num = 1;
	grid[x][y] = num;
	visited[x][y] = true;
	num++;

	for (int i = 0; i < n * m - 1; i++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!in_range(nx, ny) || visited[nx][ny]) {
			dir++;
			if (dir > 3)
				dir -= 4;
			
			nx = x + dx[dir];
			ny = y + dy[dir];
		}

		x = nx; y = ny;
		grid[x][y] = num;
		visited[x][y] = true;
		num++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}