#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int m,n;
	cin >> m >> n;
	vector <int> v(n+1, 0);

	for (int i = m; i <= n; i++) {
		v[i] = i;
	}
	v[1] = 0;
	for (int i = 2; i <= n; i ++) {
		if (v[i] == 0 && i >= m) continue;
		for (int j = 2 * i; j <= n; j += i) {
			v[j] = 0;
		}
	}
	for (int x : v) {
		if(x != 0) cout << x << '\n';
	}
}