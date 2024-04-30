#include <iostream>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dir = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y; x = y = 0;
	string cmd; cin >> cmd;

	for (int i = 0; i < cmd.size(); i++) {		
		if (cmd[i] == 'L') {
			dir--;
			if (dir < 0)
				dir += 4;
		}

		else if (cmd[i] == 'R') {
			dir++;
			if (dir >= 4)
				dir -= 4;
		}

		else if (cmd[i] == 'F') {
			x += dx[dir];
			y += dy[dir];
		}
	}

	cout << x << ' ' << y;
}