#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

char board[101][101];
bool visit[101][101];
string s[101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			board[i][j] = s[i][j];
		}
	}	

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			char color = board[i][j];

			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j] = true;
			cnt1++;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n)
						continue;
					if (visit[nx][ny] || board[nx][ny] != color)
						continue;

					q.push({ nx, ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fill(visit[i], visit[i] + n, false);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			char color = board[i][j];

			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j] = true;
			cnt2++;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n)
						continue;
					if (visit[nx][ny])
						continue;

					if (color == 'B' && board[nx][ny] != 'B')
						continue;
					if ((color == 'G' || color == 'R') && board[nx][ny] == 'B')
						continue;

					q.push({ nx, ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}

	cout << cnt1 << " " << cnt2;
	return 0;
}