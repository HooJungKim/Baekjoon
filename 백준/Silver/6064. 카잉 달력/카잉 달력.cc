#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);	
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	
	
	while (n--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;		
		int LCM = lcm(M, N);
		if (y == N) y = 0;
		bool isCal = false;
		for (int i = x; i <= LCM; i += M){
			if (i % N == y) {
				isCal = true;
				cout << i << '\n';
				break;
			}
		}
		if (isCal == false) cout << -1 << '\n';
	}
}