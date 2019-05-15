#include<iostream>
using namespace std;
/*
给定一个链表和一个特定值 x，对链表进行分隔，
使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->3->4->5
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* partition(ListNode* head, int x)
{
	if (head == nullptr)
		return head;
	ListNode left(-1);
	ListNode right(-1);
	ListNode *leftNode = &left;
	ListNode *rightNode = &right;
	for (ListNode *cur = head; cur != nullptr; cur = cur->next)
	{
		if (cur->val < x)
		{
			leftNode->next = cur;
			leftNode = cur;
		}
		else
		{
			rightNode->next = cur;
			rightNode = cur;
		}
	}
	leftNode->next = right.next;
	rightNode->next = nullptr;
	return left.next;
}
//自己做的，这可是链表，复杂度一般来说都应该是O(1)
ListNode* partition2(ListNode* head, int x)
{
	if (head == nullptr)
		return head;
	ListNode *first = new ListNode(-1);
	ListNode *second = new ListNode(-1);
	ListNode *node = head;
	ListNode *f1 = first;
	ListNode *f2 = second;
	while (node != nullptr)
	{
		if (node->val < x)
		{
			first->next = new ListNode(node->val);
			first = first->next;
		}
		else
		{
			second->next = new ListNode(node->val);
			second = second->next;
		}
		node = node->next;
	}
	first->next = f2->next;
	return f1->next;
}
int main(void)
{
	system("pasue");
	return 0;
}