#include <iostream>
using namespace std;

void Move(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	Move(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	Move(6 - a - b, b, n - 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	Move(1, 3, n);
}