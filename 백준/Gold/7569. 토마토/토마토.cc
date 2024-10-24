#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m, h;
int matrix[101][101][101];
int visit[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = { 0, 0, 0, 0, 1, -1 };
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> matrix[i][j][k];

				if (matrix[i][j][k] == 1)
					q.push(make_tuple( i, j , k ));

				if (matrix[i][j][k] == 0)
					visit[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur_node = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = dx[i] + get<2>(cur_node);
			int ny = dy[i] + get<1>(cur_node);
			int nh = dh[i] + get<0>(cur_node);

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= h)
				continue;

			if (visit[nh][ny][nx] >= 0)
				continue;

			visit[nh][ny][nx] = visit[get<0>(cur_node)][get<1>(cur_node)][get<2>(cur_node)] + 1;
			q.push({ nh, ny, nx });
		}

	}

	int answer = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {

				if (visit[i][j][k] == -1 ) {
					cout << -1;
					return 0;
				}

				answer = max(answer, visit[i][j][k]);
			}
		}
	}

	cout << answer;
	return 0;
}