#include <iostream>
#include <queue>
using namespace std;
vector<int> adj[1001];
int indegree[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;	
	while (m--) {
		int num;
		cin >> num;
		vector<int> v(num);
		for (int i = 0; i < num; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < num - 1; i++) {
			for (auto x : adj[v[i + 1]]) {
				if (x == v[i])
				{
					cout << "0";
					return 0;
				}
			}
			adj[v[i]].push_back(v[i + 1]);
			indegree[v[i + 1]]++;
		}
	}
	
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (auto x : adj[cur]) {
			indegree[x]--;
			if (indegree[x] == 0) {
				q.push(x);
			}
		}
	}
	if (result.size() == n) {
		for (int x : result) {
			cout << x << ' ';
		}
	}
	else cout << '0';
}