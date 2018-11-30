#include<iostream>
using namespace std;
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
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