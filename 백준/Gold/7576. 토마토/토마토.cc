#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int m, n;
int matrix[1001][1001];
int date[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];

			if (matrix[i][j] == 1)
				q.push({ i, j });

			if (matrix[i][j] == 0)
				date[i][j] = -1;
		}
	}

	while (!q.empty()) {

		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt_X = cur.second + dx[i];
			int nxt_Y = cur.first + dy[i];

			if (nxt_X < 0 || nxt_X >= m || nxt_Y < 0 || nxt_Y >= n)
				continue;
			if (date[nxt_Y][nxt_X] >= 0)
				continue;

			q.push({ nxt_Y , nxt_X });
			date[nxt_Y][nxt_X] = date[cur.first][cur.second] + 1;			
		}
	}
	
	int maxDate = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (date[i][j] == -1) {
				cout << -1;
				return 0;
			}
			maxDate = max(maxDate, date[i][j]);
		}
	}
	cout << maxDate;
	return 0;
}