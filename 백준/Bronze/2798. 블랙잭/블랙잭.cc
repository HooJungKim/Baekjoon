#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector <int> v;

	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	int ans = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (v[i] + v[j] + v[k] == m) {
					ans = m;
					break;
				}
				else if (v[i] + v[j] + v[k] < m) {
					if (ans < v[i] + v[j] + v[k]) 
						ans = v[i] + v[j] + v[k];
				}
				else {
					continue;
				}
			}
		}
	}

	cout << ans;
}