#include <iostream>
using namespace std;

int Power(long long  a, long long b, long long c) {
	if (b == 0) return 1;
	long long half = Power(a, b / 2, c);
	half = half * half % c;
	if (b % 2) return half * a % c;
	else return half;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	long long a, b, c;
	cin >> a >> b >> c;
	cout << Power(a, b, c);
}