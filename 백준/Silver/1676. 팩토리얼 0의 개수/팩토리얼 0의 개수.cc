#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	int cnt = 0;
	while (N != 0) {
		int num = N;
		while (num % 5 == 0) {
			num /= 5;
			cnt++;
		}		
		N--;
	}
	cout << cnt;
}