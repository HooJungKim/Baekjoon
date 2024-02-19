#include <iostream>
using namespace std;
long long Combination(int a, int b) {
	if (b - a < a) a = b - a;
	long long ans = 1;
	for (int i = 0; i < a; i++) {
		ans = ans * (b - i)/(i+1);
	}
	return ans;	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		cout << Combination(x, y)<<'\n';
	}
}