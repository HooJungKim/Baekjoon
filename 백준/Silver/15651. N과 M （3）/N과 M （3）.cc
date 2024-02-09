#include <iostream>
using namespace std;
int N, M;
int arr[9];
void BackTracking(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++) 
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {			
		arr[num] = i;
		BackTracking(num + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	BackTracking(0);

}