#include<iostream>
using namespace std;
/*
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��

˵��:
1 �� m �� n �� �����ȡ�
ʾ��:

����: 1->2->3->4->5->NULL, m = 2, n = 4
���: 1->4->3->2->5->NULL
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//ʱ�临�Ӷ�O(n)
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (m == n)
		return head;
	ListNode *node = head;
	ListNode *p = nullptr;
	int k = n - m;
	int s = m;
	//��node�ڵ�ָ���m���ڵ㣬pָ����ǰһ��
	while (m-- > 1)
	{
		p = node;
		node = node->next;
	}
	ListNode *preNode = node;
	ListNode *currentNode = node->next;
	ListNode *nextNode = nullptr;
	//��ת
	while (k-- > 0)
	{
		nextNode = currentNode->next;
		currentNode->next = preNode;
		preNode = currentNode;
		currentNode = nextNode;
	}
	//����m���ڵ����n���ڵ����һ���ڵ��������
	node->next = currentNode;
	//�ж�m�Ƿ�Ϊ1��Ҳ�����ж�ǰ���Ƿ��нڵ㣬���У���������
	if (s != 1)
	{
		p->next = preNode;
		return head;
	}
	else
		return preNode;
}

void printListValue(ListNode *node)
{
	while (node != nullptr)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}
int main(void)
{
	ListNode *m_node1 = new ListNode(1);
	ListNode *m_node2 = new ListNode(2);
	ListNode *m_node3 = new ListNode(3);
	ListNode *m_node4 = new ListNode(4);
	ListNode *m_node5 = new ListNode(5);
	ListNode *m_node6 = nullptr;
	m_node1->next = m_node2;
	m_node2->next = m_node3;
	//m_node3->next = m_node4;
	//m_node4->next = m_node5;

	m_node6 = reverseBetween(m_node1,1,1);
	printListValue(m_node6);
	system("pause");
	return 0;
}