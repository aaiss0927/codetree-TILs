#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	x = y = 0;
	int n; cin >> n;
	
	while (n--) {
		char dir;
		int dist;
		cin >> dir >> dist;

		if (dir == 'W') {
			x -= dist;
		}

		else if (dir == 'S') {
			y -= dist;
		}

		else if (dir == 'N') {
			y += dist;
		}

		else if (dir == 'E') {
			x += dist;
		}
	}

	cout << x << ' ' << y;
}