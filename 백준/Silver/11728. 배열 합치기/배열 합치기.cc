#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	vector<int> v_a(a);
	vector<int> v_b(b);
	for (int i = 0; i < a; i++) {
		cin >> v_a[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> v_b[i];
	}
	int ptr_a = 0;
	int ptr_b = 0;
	vector<int> merge(a+b);
	
	for (int i = 0; i < a + b; i++) {
		if (ptr_a >= 0 && ptr_b >= 0) {
			if (v_a[ptr_a] < v_b[ptr_b]) {
				merge[i] = v_a[ptr_a];
				if (ptr_a < v_a.size() - 1) ptr_a++;
				else ptr_a = -1;
			}
			else {
				merge[i] = v_b[ptr_b];
				if (ptr_b < v_b.size() - 1) ptr_b++;
				else ptr_b = -1;
			}
		}
		else {
			if (ptr_a < 0) {
				merge[i] = v_b[ptr_b];
				ptr_b++;
			}
			else {
				merge[i] = v_a[ptr_a];
				ptr_a++;
			}
		}
		cout << merge[i] << ' ';
	}
}