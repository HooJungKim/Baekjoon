#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[26][26];
bool visited[26][26];
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < n; j++) {
			matrix[i][j] = x[j] - '0';
		}
	}

	int cnt = 0;
	vector<int> cnts;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0 || visited[i][j] == true)
				continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			cnt++;
			int num = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nxtX = cur.first + dx[k];
					int nxtY = cur.second + dy[k];
					if (nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= n)
						continue;
					if (matrix[nxtX][nxtY] == 1 && !visited[nxtX][nxtY]) {
						q.push({ nxtX , nxtY });
						visited[nxtX][nxtY] = true;
						num++;
					}
				}
			}
			cnts.push_back(num);
		}
	}

	cout << cnt << '\n';
	sort(cnts.begin(), cnts.end());
	for (int x : cnts)
		cout << x << '\n';
}