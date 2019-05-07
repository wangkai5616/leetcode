#include"Dijkstra.h"
//���캯��
Graph_DG::Graph_DG(int vexnum, int edge)
{
	//��ʼ���������ͱ���
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
//��������
Graph_DG::~Graph_DG()
{
	delete[]dis;
	for (int i = 0; i < this->vexnum; ++i)
		delete arc[i];
	delete arc;
}
// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph_DG::check_edge_value(int start, int end, int weight)
{
	if (start<1 || end<1 || start>vexnum || end> vexnum || weight < 0)
		return false;
	return true;
}
//�����Ŵ�1��ʼ
void Graph_DG::createGraph()
{
	cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count < edge)
	{
		cin >> start >> end >> weight;
		//�����жϱߵ���Ϣ�Ƿ�Ϸ�
		while (!check_edge_value(start, end, weight))
		{
			cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
			cin >> start >> end >> weight;
		}
		arc[start - 1][end - 1] = weight;
		++count;
	}
}
void Graph_DG::print()
{
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	int count_row = 0;
	int count_col = 0;
	while (count_row < vexnum)

	{
		count_col = 0;
		while (count_col < vexnum)
		{
			if (arc[count_row][count_col] == INT_MAX)
				cout << "��" << " ";
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
	//���ȳ�ʼ��dis����
	int i;
	for (i = 0; i < vexnum; ++i)
	{
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//������㵽����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	int count = 1;
	//����ʣ��ڵ�����·��
	while (count != vexnum)
	{
		//temp���ڱ��浱ǰdis��������С���Ǹ��±�
		//min��¼���ǵ�ǰ����Сֵ
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
		//��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
		dis[temp].visit = 1;
		++count;
		for (i = 0; i < vexnum; ++i)
		{
			if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value)
			{
				//����µõ��ı߿���Ӱ������δ���ʵĶ��㣬�Ǿ͸����������·���ͳ���
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
	cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
	for (int i = 0; i != vexnum; ++i)
	{
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else
			cout << dis[i].path << "�������·����" << endl;
	}
}