#include <iostream>
using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
int dir;
int grid[50][50];
int n;

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> n >> t;
	int r, c; char d; cin >> r >> c >> d;
	r--; c--;

	if (d == 'L') {
		dir = 0;
	}

	else if (d == 'U') {
		dir = 1;
	}

	else if (d == 'D') {
		dir = 2;
	}

	else if (d == 'R') {
		dir = 3;
	}

	while (t--) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];

		if (in_range(nx, ny)) {
			r = nx; c = ny;
		}
			
		else
			dir = 3 - dir;
	}

	r++; c++;

	cout << r << ' ' << c;
}