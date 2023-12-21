#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	int r;
	
	if (a < b) swap(a, b);
	 
	r = a % b;
	if (r == 0) return b;
	else return GCD(b, r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, gcd, lcm;
	cin >> a >> b;

	gcd = GCD(a, b);
	lcm = a * b / gcd;

	cout << gcd << '\n'<< lcm;
}