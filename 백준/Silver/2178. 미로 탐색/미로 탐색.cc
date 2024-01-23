#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string maze[101];
int dist[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	
	queue<pair<int, int>> q;
	dist[0][0] = 0;
	q.push({ 0,0 });
	int curX, curY;

	while (!q.empty()) {
		curX = q.front().first;
		curY = q.front().second;
		
		for (int i = 0; i < 4; i++) {
			if (curX + dx[i] < 0 || curX + dx[i] >= n || curY + dy[i] < 0 || curY + dy[i] >= m)
				continue;
			if (maze[curX + dx[i]][curY + dy[i]] == '0' || dist[curX + dx[i]][curY + dy[i]] != -1 ) 
				continue;

			dist[curX + dx[i]][curY + dy[i]] = dist[curX][curY]+1;
			q.push({ curX + dx[i] ,curY + dy[i] });
		}
		q.pop();
	}
	cout << dist[n-1][m-1]+1;
}