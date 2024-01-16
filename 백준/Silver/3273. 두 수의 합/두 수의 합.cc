#include <iostream>
#include <vector>
using namespace std;

int arr[1000001] = { };
bool b_arr[2000001] = { false };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;		
		arr[i] = num;
		b_arr[num] = true;
	}

	int x, ans = 0;
	cin >> x;

	for (int i = 1; i < n; i++) {
		if (x - arr[i] > 0 && b_arr[x - arr[i]] == true) ans++;
	}
	cout << (ans+1)/2;
}