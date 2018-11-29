#include<iostream>
using namespace std;
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
	return head;
}