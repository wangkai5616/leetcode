#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。
例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
string simplifyPath(string path)
{
	string result;
	//用于存放一段一段中的目录名
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
		//j是下一个'/'的位置
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