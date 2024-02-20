#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b + c <= 2 * max({ a, b, c })) {
		cout << (a + b + c - max({ a, b, c }))* 2 - 1;
	}
	else {
		cout << a + b + c;
	}
}