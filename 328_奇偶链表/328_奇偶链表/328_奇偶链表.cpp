#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *node1 = head, *node2 = head->next;
	ListNode *temp = head->next;
	while (node2 && node2->next)
	{
		node1->next = node2->next;
		node1 = node1->next;
		node2->next = node1->next;
		node2 = node1->next;
	}
	node1->next = temp;
	return head;
}
