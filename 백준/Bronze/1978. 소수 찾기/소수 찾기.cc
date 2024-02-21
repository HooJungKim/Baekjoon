#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans= 0 ;
	while (n--) {
		int num;
		bool isPrime = true;
		cin >> num;
		if (num == 1) isPrime = false;
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) ans++;
	}
	cout << ans;
}