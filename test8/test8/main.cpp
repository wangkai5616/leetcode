#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<memory>
using namespace std;
string simplifyPath(string path)
{
	stack<string> ss;
	string result;
	if (path.size() == 0 || path[0] != '/')
		return result;
	string s;
	for (int i = 1; i < path.size(); ++i)
	{
		if (path[i] == '/')
		{
			if (s.size() > 0)
				ss.push(s);
		}
			else if (path[i] == '.')
			{

			}

		

	}
}
int main(void)
{
	
	system("pause");
	return 0;
}




