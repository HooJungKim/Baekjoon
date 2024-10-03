#include <iostream>
#include <algorithm>
using namespace std;

int n;
int fruits[200001];
int f_cnt[10];
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> fruits[i];
	}

	int st= 0, end = 0;
	int cur_fruits = 1;
	int max_length = 1;

	f_cnt[fruits[0]]++;


	while (end < n -1) {
		//과일 수가 2 이하인 경우
		if (cur_fruits <= 2) {
			// Index 뒤로 한 칸 밀기
			end++;

			if (f_cnt[fruits[end]] == 0)				
				cur_fruits++;
				
			f_cnt[fruits[end]]++;
			if (cur_fruits < 3)
				max_length = max(max_length, end - st + 1);
		}
		else { // 과일 수가 3이상인 경우

			f_cnt[fruits[st]]--;
			// Index 앞에서 한 칸 제거
			if (f_cnt[fruits[st]] == 0)
				cur_fruits--;
			
			st++;
		}
	}

	cout << max_length;
	return 0;
}