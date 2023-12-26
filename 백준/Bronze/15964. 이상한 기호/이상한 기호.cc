#include <iostream>
using namespace std;

int Func(int a, int b) {
	return (a + b) * (a - b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	cout << Func(A, B);
}