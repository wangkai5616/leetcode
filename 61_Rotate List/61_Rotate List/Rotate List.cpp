#include<iostream>
using namespace std;
/*
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
*/
/*
˼·��
�ȱ���һ�飬�ó������� len��ע�� k ���ܴ��� len������� k% = len��
��β�ڵ� next ָ��ָ���׽ڵ㣬�γ�һ���������������� len ? k ����
������Ͽ�������Ҫ��Ľ���ˡ�
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
	if(head==nullptr || head->next==nullptr || k<1)
		return head;
	ListNode *node = head;

	int length = 1;
	while (node->next != nullptr)
	{
		length++;
		node = node->next;
	}
	int num = length - k % length;
	node->next = head;//����������β��ͷ������
	for (int step = 0; step < num; ++step)
		node = node->next;
	head = node->next;//�µ�ͷ�ڵ�
	node->next = nullptr;//�Ͽ���
	return head;
}
int main(void)
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);

	node1->next = node2;
	node2->next = node3;

	node1 = rotateRight(node1,1);
	system("pause");
	return 0;
}