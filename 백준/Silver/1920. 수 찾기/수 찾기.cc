#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	vector <int> vn;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vn.push_back(x);
;	}

	sort(vn.begin(), vn.end());

	cin >> m;
	while (m--) {
		int y;
		cin >> y;
		cout << binary_search(vn.begin(), vn.end(), y) << '\n';
	}
}