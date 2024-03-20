#include <iostream>
#include <vector>
#include <algorithm>
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

	queue<int> q;
	visit[1] = true;
	int answer = 0;
	for (int nxt : adj[1]) {
		q.push(nxt);
		visit[nxt] = true;
		answer++;
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur]) {
			if (visit[nxt]) continue;
			visit[nxt] = true;
			answer++;
		}
	}
	cout << answer;
}
