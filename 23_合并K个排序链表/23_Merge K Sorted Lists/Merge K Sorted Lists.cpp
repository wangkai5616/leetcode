#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
//�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�

//ʱ�临�Ӷ� O(n1+n2+...)���ռ临�Ӷ� O(1)
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
//������,����Ԫ�ض��ȷŵ������У�Ȼ����һ������
ListNode* mergeKLists(vector<ListNode*>&lists)
{
	ListNode* result = new ListNode(-1);
	ListNode* point = result;
	vector<int> l;
	for (int i = 0; i<lists.size(); i++)
	{
		while (lists[i])
		{
			l.push_back(lists[i]->val);
			lists[i] = lists[i]->next;
		}
	}
	sort(l.begin(),l.end());
	for (vector<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		point->next = new ListNode(*it);
		point = point->next;
	}
	return result->next;
}
int main(void)
{
	system("pause");
	return 0;
}