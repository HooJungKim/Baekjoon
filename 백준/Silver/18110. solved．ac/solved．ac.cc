#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	if (n == 0) cout << 0;
	else {
		vector<int> x(n);
		for (int i = 0; i < n; i++) cin >> x[i];
		sort(x.begin(), x.end());
		int cut = round((float)n * 0.15);
		int sum = 0;
		for (int i = cut; i < n - cut; i++) {
			sum += x[i];
		}
		cout << round((float)sum / (float)(n - cut * 2));
	}

}