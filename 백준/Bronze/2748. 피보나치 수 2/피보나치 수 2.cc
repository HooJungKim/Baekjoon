#include <iostream>
using namespace std;

long long Fibonacci(int n) {
	long long arr[91];
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 91; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cout << Fibonacci(N);
}