#include <iostream>
#include <cmath>
using namespace std;
#define M 1234567891

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	long long sum = 0;
	long long x, r = 1;

	for (int i = 0; i < s.size(); i++) {
		sum += (s[i] - 'a' + 1) * r % M;
		sum %= M;
		r = (r * 31) % M;
	}
	cout << sum;
}