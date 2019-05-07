#pragma once
#include<iostream>
#include<string>
using namespace std;
//��¼��㵽ÿ����������·������Ϣ
struct Dis {
	string path;//��㵽��������·��
	int value;//��㵽��������·��ֵ֮��
	bool visit;//�Ƿ��Ѿ�ͳ�ƹ���
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};
class Graph_DG {
private:
	int vexnum;//ͼ�Ķ������
	int edge;//ͼ�ı���
	int **arc;//�ڽӾ��󣬴洢ͼ
	Dis *dis;//��¼�����������·������Ϣ
public:
	Graph_DG(int vexnum, int edge);
	~Graph_DG();
	//�ж�����ÿ������ıߵ���Ϣ�Ƿ�Ϸ�
	//�����1��ʼ���
	bool check_edge_value(int start, int end, int weight);
	//����ͼ
	void createGraph();
	//��ӡ�ڽӾ���
	void print();
	//�����·��
	void Dijkstra(int begin);
	//��ӡ���·��
	void print_path(int);
};