#include<iostream>
using namespace std;
//�� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//˼·���鲢����ʱ�临�Ӷ� O(nlogn)���ռ临�Ӷ� O(1)
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
ListNode* sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *slow = head;//��ָ��
	ListNode *fast = head;//��ָ��
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	//�Ͽ�����
	fast = slow;
	slow = slow->next;
	fast->next = nullptr;
	//ǰ�������
	ListNode *l1 = sortList(head);
	//��������
	ListNode *l2 = sortList(slow);
	return mergeTwoLists(l1, l2);
}
//�ϲ�������������
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode temp(-1);
	ListNode *node = &temp;
	for (; l1 != nullptr || l2 != nullptr; node = node->next)
	{
		int value1 = l1 == nullptr ? INT_MAX : l1->val;
		int value2 = l2 == nullptr ? INT_MAX : l2->val;
		if (value1 <= value2)
		{
			node->next = l1;
			l1 = l1->next;
		}
		else
		{
			node->next = l2;
			l2 = l2->next;
		}
	}
	return temp.next;
}
int main(void)
{
	system("pause");
	return 0;
}