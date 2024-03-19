#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
bool visit[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int st, end;
		cin >> st >> end;
		adj[st].push_back(end);
		adj[end].push_back(st);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		queue<int> q;
		q.push(i);
		visit[i] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int num : adj[cur]) {
				if (visit[num]) continue;
				q.push(num);
				visit[num] = true;
			}
		}
		answer++;
	}
	cout << answer;
}
