#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1);
	vector<int> indegree(n + 1);
	queue<int> q;
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int node = q.front();
		cout << node << ' ';
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			indegree[v[node][i]]--;
			if (indegree[v[node][i]] == 0)
				q.push(v[node][i]);
		}
	}

}