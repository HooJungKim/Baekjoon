#include <iostream>
using namespace std;

int Z(int N, int r, int c) {
	int div = 1 << (N-1);
	if (N == 0) return 0;
	if (r < div && c < div) return Z(N - 1, r, c);
	if (r < div && c >= div) return div * div + Z(N - 1, r, c- div);
	if (r >= div && c < div) return 2 * div * div + Z(N - 1, r- div, c);
	if (r >= div && c >= div) return 3 * div * div + Z(N - 1, r- div, c- div);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int N, r, c;
	cin >> N >> r >> c;
	cout << Z(N, r, c);	
}