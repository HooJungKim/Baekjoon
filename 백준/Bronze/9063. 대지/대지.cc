#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int width = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
	int height = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
	cout << width * height;
}