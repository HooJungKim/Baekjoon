#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (!cin.eof()) {
		stack<char> s;

		string str;
		getline(cin, str);
		if (str == ".") break;

		for (char element : str) {
			if (element == '[' || element == ']' || element == '(' || element == ')') {
				if (s.empty()) {
					s.push(element);
				}
				else {
					if (s.top() == '(' && element == ')') s.pop();
					else if (s.top() == '[' && element == ']') s.pop();
					else {
						s.push(element);
					}
				}
			}				
		}
		if (s.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}