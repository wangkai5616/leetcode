#include<iostream>
using namespace std;
//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//思路：归并排序，时间复杂度 O(nlogn)，空间复杂度 O(1)

ListNode *sortList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *slow = head;
	ListNode *fast = head;
	ListNode *pre = head;
	while (fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;
	return merge(sortList(head), sortList(slow));
}
ListNode *merge(ListNode *l1, ListNode *l2)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *cur = dummy;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	return dummy->next;
}
int main(void)
{
	system("pause");
	return 0;
}