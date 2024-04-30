#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int x, y; x = y = 0;
	int t = 0;

	while (n--) {
		char dir; int dist; cin >> dir >> dist;

		if (dir == 'N') {
			while (dist--) {
				x += dx[0];
				t++;
				if (x == 0 && y == 0) {
					cout << t;
					return 0;
				}
			}
		}

		else if (dir == 'W') {
			while (dist--) {
				y += dy[1];
				t++;
				if (x == 0 && y == 0) {
					cout << t;
					return 0;
				}
			}
		}

		else if (dir == 'S') {
			while (dist--) {
				x += dx[2];
				t++;
				if (x == 0 && y == 0) {
					cout << t;
					return 0;
				}
			}
		}

		else if (dir == 'E') {
			while (dist--) {
				y += dy[3];
				t++;
				if (x == 0 && y == 0) {
					cout << t;
					return 0;
				}
			}
		}
	}

	cout << -1;
}