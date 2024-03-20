#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lc[27];
int rc[27];
void Preorder (int root) {
	cout << char(root + 'A'-1);
	if (lc[root] != 0)
		Preorder(lc[root]);
	if (rc[root] != 0)
		Preorder(rc[root]);
}
void Inorder(int root) {
	if (lc[root] != 0)
		Inorder(lc[root]);
	cout << char(root + 'A' - 1);
	if (rc[root] != 0)
		Inorder(rc[root]);
}
void Postorder(int root) {
	if (lc[root] != 0)
		Postorder(lc[root]);
	if (rc[root] != 0)
		Postorder(rc[root]);
	cout << char(root + 'A' - 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c, l, r;
		cin >> c >> l >> r;
		if (l != '.')
			lc[c - 'A' + 1] = l - 'A' + 1;		
		if (r != '.')
			rc[c - 'A' + 1] = r - 'A' + 1;
	}
	Preorder(1);
	cout << '\n';
	Inorder(1);
	cout << '\n';
	Postorder(1);
}
