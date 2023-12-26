#include <iostream>
using namespace std;
int Fib(int n) {
	int arr[46];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 46; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << Fib(n);
}