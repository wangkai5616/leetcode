#include<iostream>
using namespace std;
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
void reorderList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return;
	ListNode *fast = head;
	ListNode *slow = head;
	//将一个链表平均分开
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = nullptr;
	ListNode *head2 = reverse(fast);
	ListNode *head1 = head;
	//合并两个链表
	while (head1->next)
	{
		ListNode *temp = head1->next;
		head1->next = head2;
		head2 = head2->next;
		head1->next->next = temp;
		head1 = temp;
	}
	head1->next = head2;
}

//反转链表
ListNode *reverse(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *node = head;
	ListNode *tail = nullptr;
	while (node != nullptr)
	{
		ListNode *temp = node->next;
		node->next = tail;
		tail = node;
		node = temp;
	}
	return tail;
}

int main(void)
{
	system("pause");
	return 0;
}