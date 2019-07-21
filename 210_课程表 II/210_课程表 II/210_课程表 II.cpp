#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	//ÿ��������ȵĶ��㼯��
	vector<vector<int>> graph(numCourses, vector<int>());
	//��ʾÿ����������
	vector<int> in(numCourses);
	for (auto a : prerequisites)
	{
		graph[a[1]].push_back(a[0]);
		++in[a[0]];
	}
	vector<int> result;
	queue<int> q;
	for (int i = 0; i < numCourses; ++i)
		if (in[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int value = q.front();
		result.push_back(value);
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
			return vector<int>();
	return result;
}