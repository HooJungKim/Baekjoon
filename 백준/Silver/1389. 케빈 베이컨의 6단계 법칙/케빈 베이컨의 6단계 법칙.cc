#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int table[101][101];
const int INF = 0x3f3f3f3f;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(table[i], table[i] + n + 1, INF);
		table[i][i] = 0;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		table[a][b] = 1;
		table[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (table[i][j] > table[i][k] + table[k][j])
					table[i][j] = table[i][k] + table[k][j];
			}
		}
	}
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i)
				continue;

			v[i] += table[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == *min_element(v.begin() + 1, v.end())) {
			cout << i;
			break;
		}
	}
}