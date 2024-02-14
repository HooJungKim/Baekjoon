#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n+1);
	v[1] = 0;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + 1;
		if (i % 3 == 0) v[i] = min(v[i / 3] + 1, v[i]);
		if (i % 2 == 0) v[i] = min(v[i / 2] + 1, v[i]);
	}
	cout << v[n];
}