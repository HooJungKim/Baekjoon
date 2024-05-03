#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[500001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	int val;
	while (m--)
	{
		cin >> val;
		cout << binary_search(arr, arr + n, val) << ' ';
	}
}