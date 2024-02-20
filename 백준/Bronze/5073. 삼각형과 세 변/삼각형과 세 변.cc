#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (a + b + c <= 2 * max({ a, b, c })) cout << "Invalid\n";
		else {
			if (a != b && b != c && a != c) cout << "Scalene\n";
			else if (a == b && b == c) cout << "Equilateral\n";
			else cout << "Isosceles\n";
		}
	}
}