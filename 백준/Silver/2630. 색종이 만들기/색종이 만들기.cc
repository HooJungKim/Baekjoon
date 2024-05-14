#include <iostream>
using namespace std;
int square[128][128];
int blue, white;
void Recur(int w_st, int w, int h_st, int h) {
	bool allSame = true;
	for (int i = w_st; i < w; i++) {
		for (int j = h_st; j < h; j++) {
			if (square[w_st][h_st] != square[i][j]) {
				allSame = false;
				break;
			}
		}
	}

	if (allSame) {
		if (square[w_st][h_st] == 0) white++;
		else blue++;
		return;
	}
	else {
		Recur(w_st, w_st + (w - w_st) / 2, h_st, h_st + (h - h_st) / 2);
		Recur(w_st + (w - w_st) / 2, w, h_st, h_st + (h - h_st) / 2);
		Recur(w_st, w_st + (w - w_st) / 2, h_st + (h - h_st) / 2, h);
		Recur(w_st + (w - w_st) / 2, w, h_st + (h - h_st) / 2, h);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> square[i][j];
		}
	}

	Recur(0,n ,0, n);
	cout << white << '\n' << blue;
}