#include<iostream>
using namespace std;
/*
����һ�������һ���ض�ֵ x����������зָ���
ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
ʾ��:

����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->3->4->5
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
//�Լ����ģ�������������Ӷ�һ����˵��Ӧ����O(1)
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