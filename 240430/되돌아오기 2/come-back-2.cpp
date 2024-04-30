#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dir;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str; cin >> str;
	int x, y; x = y = 0;
	int t = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			dir++;
			if (dir > 3)
				dir -= 4;
			t++;
		}

		else if (str[i] == 'R') {
			dir--;
			if (dir < 0)
				dir += 4;
			t++;
		}

		else if (str[i] == 'F') {
			x += dx[dir];
			y += dy[dir];
			t++;

			if (x == 0 && y == 0) {
				cout << t;
				return 0;
			}
		}
	}

	cout << -1;
}