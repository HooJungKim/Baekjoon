#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >>k;
	vector <int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];

	int index = n - 1;
	int answer = 0;
	while (1) {
		if (index < 0 || k == 0) break;
		if (v[index] <= k) {
			answer += k / v[index];
			k %= v[index];
		}
		index--;
	}
	cout << answer;
}