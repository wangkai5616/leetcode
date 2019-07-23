#include<iostream>
#include<string>
#include<stack>
using namespace std;
int calculate(string s) {
	long res = 0, num = 0, n = s.size();
	char op = '+';
	stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] >= '0') {
			num = num * 10 + s[i] - '0';
		}
		if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
			if (op == '+') 
				st.push(num);
			if (op == '-') 
				st.push(-num);
			if (op == '*' || op == '/') {
				int tmp = (op == '*') ? st.top() * num : st.top() / num;
				st.pop();
				st.push(tmp);
			}
			op = s[i];
			//cout << op << endl;
			num = 0;
		}
	}
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}
int main(void)
{
	string s = "1-2*3";
	cout << calculate(s) << endl;
	system("pause");
	return 0;
}