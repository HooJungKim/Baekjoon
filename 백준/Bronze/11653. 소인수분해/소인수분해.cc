#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	
	vector<int> v;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n = n / i;
			v.push_back(i);
		}
	}
	if (n != 1) v.push_back(n);
	for (int i : v) cout << i << '\n';
}