#pragma once
#include<iostream>
#include<string>
using namespace std;
//记录起点到每个顶点的最短路径的信息
struct Dis {
	string path;//起点到这个顶点的路径
	int value;//起点到这个顶点的路径值之和
	bool visit;//是否已经统计过了
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};
class Graph_DG {
private:
	int vexnum;//图的顶点个数
	int edge;//图的边数
	int **arc;//邻接矩阵，存储图
	Dis *dis;//记录各个顶点最短路径的信息
public:
	Graph_DG(int vexnum, int edge);
	~Graph_DG();
	//判断我们每次输入的边的信息是否合法
	//顶点从1开始编号
	bool check_edge_value(int start, int end, int weight);
	//创建图
	void createGraph();
	//打印邻接矩阵
	void print();
	//求最短路径
	void Dijkstra(int begin);
	//打印最短路径
	void print_path(int);
};