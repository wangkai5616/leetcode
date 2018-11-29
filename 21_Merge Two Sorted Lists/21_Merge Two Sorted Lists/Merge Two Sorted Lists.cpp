#include<iostream>
using namespace std;
/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	ListNode *node = new ListNode(-1);
	ListNode *head = node;
	for (; l1 != nullptr && l2 != nullptr; )
	{
		if (l1->val < l2->val)
		{
			node->next = l1;
			l1 = l1->next;
		}
		else
		{
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}
	if (l1 == nullptr)
		node->next = l2;
	else
		node->next = l1;
	return head->next;
}
int main(void)
{
	system("pause");
	return 0;
}