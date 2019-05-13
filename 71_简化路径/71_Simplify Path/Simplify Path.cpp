#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
����һ���ĵ� (Unix-style) ����ȫ·���������·���򻯡�
���磬
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
string simplifyPath(string path)
{
	string result;
	//���ڴ��һ��һ���е�Ŀ¼��
	vector<string> dirs;
	for (auto i = path.begin(); i != path.end();)
	{
		++i;
		auto j = find(i, path.end(), '/');
		string dir = string(i, j);
		cout << dir << endl;
		if (!dir.empty() && dir != ".")
		{
			if (dir == "..")
			{
				if (!dirs.empty())
					dirs.pop_back();
			}
			else
				dirs.push_back(dir);
		}
		//j����һ��'/'��λ��
		i = j;
	}
	if (dirs.empty())
		result = "/";
	else
	{
		for (auto dir : dirs)
			result = result + "/" + dir;
	}
	return result;
}
int main(void)
{
	string s = "/home/";
	string result = simplifyPath(s);
	cout << result << endl;
	system("pause");
	return 0;
}