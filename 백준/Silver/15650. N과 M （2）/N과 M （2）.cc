#include <iostream>
using namespace std;
int N, M;
int arr[9];
bool is_visited[9];
void BackTracking(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++) 
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!is_visited[i]) {
			if (num == 0) {
				arr[num] = i;
				is_visited[i] = true;
				BackTracking(num + 1);
				is_visited[i] = false;
			}
			else {
				if (arr[num - 1] < i) {
					arr[num] = i;
					is_visited[i] = true;
					BackTracking(num + 1);
					is_visited[i] = false;
				}
			}		
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	BackTracking(0);

}