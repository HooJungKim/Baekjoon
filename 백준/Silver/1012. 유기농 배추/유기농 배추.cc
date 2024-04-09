#include <iostream>
#include <queue>
using namespace std;
int arr[52][52];
bool visited[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int bfs(int m, int n) {
	int ans = 0;	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				queue<pair<int, int>> q;
				q.push({i, j});
				visited[i][j] = true;
				while (!q.empty()) {
					for (int i = 0; i < 4; i++) {
						int mx = q.front().first + dx[i];
						int my = q.front().second + dy[i];
						if (mx >= 0 && mx < m && my >= 0 && my < n) {
							if (arr[mx][my] == 1 && visited[mx][my] == false) {
								q.push({ mx, my });
								visited[mx][my] = true;
							}
						}
					}
					q.pop();
				}
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int m, n, k;
		cin >> m >> n >> k;
		int x, y;
		while (k--) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		cout << bfs(m, n) << '\n';
		for (int i = 0; i < m; i++) {
			fill(arr[i], arr[i] + n, 0);
			fill(visited[i], visited[i] + n, false);
		}
	}
}