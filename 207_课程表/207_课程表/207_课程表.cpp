#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
BFS 的解法，我们定义二维数组 graph 来表示这个有向图，一维数组 in 来表示
每个顶点的入度。我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。
然后我们定义一个 queue 变量，将所有入度为0的点放入队列中，然后开始遍历队列，
从 graph 里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度
为0，则放入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，
则说明环存在，返回 false，反之则返回 true。
*/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	//每个顶点出度的顶点集合
	vector<vector<int>> graph(numCourses, vector<int>());
	//表示每个顶点的入度
	vector<int> in(numCourses);
	for (auto a : prerequisites)
	{
		//[3,2] 2->3
		graph[a[1]].push_back(a[0]);
		++in[a[0]];
	}
	queue<int> q;
	for (int i = 0; i < numCourses; ++i)
		if (in[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		for (auto a : graph[value])
		{
			--in[a];
			if (in[a] == 0)
				q.push(a);
		}
	}
	for (int i = 0; i < numCourses; ++i)
		if (in[i] != 0)
			return false;
	return true;
}
int main()
{
	system("pause");
	return 0;
}