#include"Dijkstra.h"
//构造函数
Graph_DG::Graph_DG(int vexnum, int edge)
{
	//初始化顶点数和边数
	this->vexnum = vexnum;
	this->edge = edge;
	arc = new int*[this->vexnum];
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; ++i)
	{
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; ++k)
			arc[i][k] = INT_MAX;
	}
}
//析构函数
Graph_DG::~Graph_DG()
{
	delete[]dis;
	for (int i = 0; i < this->vexnum; ++i)
		delete arc[i];
	delete arc;
}
// 判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight)
{
	if (start<1 || end<1 || start>vexnum || end> vexnum || weight < 0)
		return false;
	return true;
}
//顶点编号从1开始
void Graph_DG::createGraph()
{
	cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count < edge)
	{
		cin >> start >> end >> weight;
		//首先判断边的信息是否合法
		while (!check_edge_value(start, end, weight))
		{
			cout << "输入的边的信息不合法，请重新输入" << endl;
			cin >> start >> end >> weight;
		}
		arc[start - 1][end - 1] = weight;
		++count;
	}
}
void Graph_DG::print()
{
	cout << "图的邻接矩阵为：" << endl;
	int count_row = 0;
	int count_col = 0;
	while (count_row < vexnum)

	{
		count_col = 0;
		while (count_col < vexnum)
		{
			if (arc[count_row][count_col] == INT_MAX)
				cout << "∞" << " ";
			else
				cout << arc[count_row][count_col] << " ";
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}
void Graph_DG::Dijkstra(int begin)
{
	//首先初始化dis数组
	int i;
	for (i = 0; i < vexnum; ++i)
	{
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//设置起点到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	int count = 1;
	//计算剩余节点的最短路径
	while (count != vexnum)
	{
		//temp用于保存当前dis数组中最小的那个下标
		//min记录的是当前的最小值
		int temp = 0;
		int min = WINT_MIN;
		for (i = 0; i < vexnum; ++i)
		{
			if (!dis[i].visit && dis[i].value < min)
			{
				min = dis[i].value;
				temp = i;
			}
		}
		//把temp对应的顶点加入到已经找到的最短路径的集合中
		dis[temp].visit = 1;
		++count;
		for (i = 0; i < vexnum; ++i)
		{
			if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value)
			{
				//如果新得到的边可以影响其它未访问的顶点，那就更新它的最短路径和长度
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
			}
		}
	}
}
void Graph_DG::print_path(int begin)
{
	string str;
	str = "v" + to_string(begin);
	cout << "以" << str << "为起点的图的最短路径为：" << endl;
	for (int i = 0; i != vexnum; ++i)
	{
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else
			cout << dis[i].path << "是无最短路径的" << endl;
	}
}