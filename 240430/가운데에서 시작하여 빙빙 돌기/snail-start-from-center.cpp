#include <iostream>
#include <tuple>
using namespace std;

int n;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int dir;
int grid[100][100];
bool visited[100][100];

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int x, y; x = y = n - 1;

	int num = n * n;
	grid[x][y] = num;
	visited[x][y] = true;
	num--;

	for (int i = 0; i < n * n - 1; i++) {
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
		num--;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}