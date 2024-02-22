#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int caseN = 1;
	while (true) {
		long long l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		long long ans = 0;
		if(v % p > l){
			ans = v / p * l + l;
		}
		else ans = v / p * l + v % p;

;		cout << "Case " << caseN << ": " << ans << '\n';
		caseN++;
	}
}