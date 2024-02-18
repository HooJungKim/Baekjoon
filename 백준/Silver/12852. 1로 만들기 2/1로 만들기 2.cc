#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	vector<int> route(n + 1, 0);
	v[1] = 0;
	route[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + 1;
		route[i] = i - 1;
		if (i % 2 == 0) {
			v[i] = min(v[i], v[i / 2] + 1);
			if (v[i] > v[i / 2]) route[i] = i / 2;
		}
		if (i % 3 == 0) {
			v[i] = min(v[i], v[i / 3] + 1);
			if (v[i] > v[i / 3]) route[i] = i / 3;
		}
	}
	cout << v[n] << '\n';
	int index = n;
	cout << n <<' ';
	while (index != 1) {		
		cout << route[index] << ' ';
		index = route[index];
	}
}