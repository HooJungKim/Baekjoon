#include <iostream>
#include <queue>
using namespace std;
vector<int> p(1000001, -1);
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
void un(int x, int y) {
	int parX = find(x);
	int parY = find(y);
	if (parX == parY) return;
	if (p[parX] == p[parY]) p[parX]--;
	if (p[parX] < p[parY]) p[parY] = parX;
	else p[parX] = parY;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int uf, a, b;
		cin >> uf >> a >> b;
		if (uf == 0) {
			un(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}