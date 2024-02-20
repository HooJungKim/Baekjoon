#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
int arr[8001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		arr[v[i]+4000]++;
	}
	int max_cnt = *max_element(arr, arr + 8001);
	
	vector<int> v_arr;	
	for (int i = 0; i < 8001; i++) {
		if (arr[i] == max_cnt) v_arr.push_back(i-4000);
	}	
	sort(v_arr.begin(), v_arr.end());
	float average = round(accumulate(v.begin(), v. end(), 0.0)/v.size());
	if (average == -0) average = 0;
	sort(v.begin(), v.end());

	cout << average << '\n' << v[n / 2] << '\n';
	if (v_arr.size() < 2) cout << v_arr[0] << '\n';
	else cout<<  v_arr[1] << '\n';	
	cout << v[n - 1] - v[0];
}