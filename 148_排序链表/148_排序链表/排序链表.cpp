#include<iostream>
using namespace std;
//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//思路：归并排序，时间复杂度 O(nlogn)，空间复杂度 O(1)
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
ListNode* sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *slow = head;//慢指针
	ListNode *fast = head;//快指针
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	//断开链表
	fast = slow;
	slow = slow->next;
	fast->next = nullptr;
	//前半段排序
	ListNode *l1 = sortList(head);
	//后半段排序
	ListNode *l2 = sortList(slow);
	return mergeTwoLists(l1, l2);
}
//合并两个有序链表
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