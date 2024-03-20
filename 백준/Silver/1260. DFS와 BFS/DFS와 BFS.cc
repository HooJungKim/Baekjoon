#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
vector<int> adj[1001];
bool visit[1001];

void DFS(int v) {
	stack<int> s;
	s.push(v);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (visit[cur]) continue;
		visit[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][adj[cur].size() - 1 - i];
			if (visit[next]) continue;
			s.push(next);
		}		
	}
}
void BFS(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int num : adj[cur]) {
			if (visit[num]) continue;
			q.push(num);
			visit[num] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, v;
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		int st, end;
		cin >> st >> end;
		adj[st].push_back(end);
		adj[end].push_back(st);
	}
	for (int i = 1; i <= n; i++) 
		sort(adj[i].begin(), adj[i].end());

	DFS(v);
	cout << '\n';
	fill(visit + 1, visit + n + 1, false);
	BFS(v);	
}
