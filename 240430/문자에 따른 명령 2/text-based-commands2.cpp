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
		int nx, ny;
		nx = x; ny = y;
		
		if (cmd[i] == 'L') {
			dir--;
		}

		else if (cmd[i] == 'R') {
			dir++;
		}

		else if (cmd[i] == 'F') {
			nx = x + dx[(dir + 4) % 4];
			ny = y + dy[(dir + 4) % 4];
		}

		x = nx; y = ny;
	}

	cout << x << ' ' << y;
}