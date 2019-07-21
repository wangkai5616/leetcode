#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
BFS �Ľⷨ�����Ƕ����ά���� graph ����ʾ�������ͼ��һά���� in ����ʾ
ÿ���������ȡ����ǿ�ʼ�ȸ��������������������ͼ�������������Ҳ��ʼ���á�
Ȼ�����Ƕ���һ�� queue ���������������Ϊ0�ĵ��������У�Ȼ��ʼ�������У�
�� graph ����������ӵĵ㣬ÿ����һ���½ڵ㣬������ȼ�һ�������ʱ�õ����
Ϊ0����������ĩβ��ֱ����������������е�ֵ������ʱ���нڵ����Ȳ�Ϊ0��
��˵�������ڣ����� false����֮�򷵻� true��
*/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	//ÿ��������ȵĶ��㼯��
	vector<vector<int>> graph(numCourses, vector<int>());
	//��ʾÿ����������
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