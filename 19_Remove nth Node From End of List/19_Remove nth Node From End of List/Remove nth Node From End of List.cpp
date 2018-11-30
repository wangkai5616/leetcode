#include<iostream>
using namespace std;
/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.
��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr)
		return head;
	ListNode *node = new ListNode(-1);
	node->next = head;
	ListNode *firstNode = node;
	ListNode *secondNode = node;
	for (int i = 0; i < n; ++i)
		firstNode = firstNode->next;
	if (firstNode == nullptr)
	{
		delete node;
		node = nullptr;
	}
	while (firstNode->next != nullptr)
	{
		secondNode = secondNode->next;
		firstNode = firstNode->next;
	}
	ListNode *deleteNode = secondNode->next;
	secondNode->next = deleteNode->next;
	delete deleteNode;
	deleteNode = nullptr;
	return node->next;
}