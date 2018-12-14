#include<iostream>
using namespace std;
/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
示例 :

给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//递归，时间复杂度O(n)，空间复杂度O(1)
ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2)
		return head;
	ListNode *next_group = head;
	for (int i = 0; i < k; ++i)
	{
		if (next_group)
			next_group = next_group->next;
		else
			return head;
	}
	//next_group是下一组k个节点的头
	//new_next_group是下一组k个节点的新的头
	//1->2->3<-4,然后3->nullptr，所以，此时,next_group是3，
	//而new_next_group是4
	ListNode *new_next_group = reverseKGroup(next_group, k);
	ListNode *prev = nullptr, *cur = head;
	//注意：这里判断指向的是next_group
	while (cur!= next_group)
	{
		ListNode *next = cur->next;
		cur->next = prev ? prev : new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;
}
int main(void)
{
	system("pause");
	return 0;
}