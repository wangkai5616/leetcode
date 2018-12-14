#include<iostream>
#include<vector>
using namespace std;
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

//时间复杂度 O(n1+n2+...)，空间复杂度 O(1)
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	if (lists.size() < 1)
		return nullptr;
	ListNode *p = lists[0];
	for (int i = 1; i < lists.size(); ++i)
		p = mergeTwoLists(p, lists[i]);
	return p;
}
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