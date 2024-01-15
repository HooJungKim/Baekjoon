#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[500][500];
int visit[500][500];

int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int num = 0, max_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || visit[i][j]==1) continue;

			num++;
			int cnt = 0;
			queue <pair<int, int>> q;
			visit[i][j] = 1;
			q.push({ i, j });

			while (!q.empty()) {
				cnt++;

				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					if (x + move_x[k] < 0 || x + move_x[k] >= n || y + move_y[k] < 0 || y + move_y[k] >= m)
						continue;
					
					if (board[x + move_x[k]][y + move_y[k]] == 1 && visit[x + move_x[k]][y + move_y[k]] == 0) {
						q.push({ x + move_x[k] ,y + move_y[k] });
					}
					visit[x + move_x[k]][y + move_y[k]] = 1;
				}
			}
			max_count = max(max_count, cnt);
		}
	}
	cout << num << '\n' << max_count;
}