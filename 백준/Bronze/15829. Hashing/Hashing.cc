#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	long long sum = 0;
	long long x;

	for (int i = 0; i < s.size(); i++) {
		x = (s[i]-'a' + 1) * pow(31, i);
		sum += x % 1234567891;
	}
	cout << sum;
}