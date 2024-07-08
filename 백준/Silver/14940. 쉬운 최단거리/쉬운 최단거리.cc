#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[1001][1001];
bool visit[1001][1001];
int dist[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				q.push({ i, j });
				visit[i][j] = true;
			}
				
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (map[ny][nx] == 0 || visit[ny][nx]) continue;

			visit[ny][nx] = true;
			dist[ny][nx] = dist[cur.first][cur.second] + 1;

			q.push({ ny, nx });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(map[i][j] == 0)
				cout << "0 ";
			else {
				if (!visit[i][j])
					cout << "-1 ";
				else
					cout << dist[i][j] << " ";
			}				
		}
		cout << '\n';
	}
	return 0;
}