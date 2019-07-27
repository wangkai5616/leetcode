#include<iostream>
using namespace std;
/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseBetween(ListNode *head, int m, int n)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *pre = dummy;
	dummy->next = head;
	for (int i = 0; i < m - 1; ++i) pre = pre->next;
	ListNode *cur = pre->next;
	for (int i = m; i < n; ++i)
	{
		ListNode *t = cur->next;
		cur->next = t->next;
		t->next = pre->next;
		pre->next = t;
	}
	return dummy->next;
}
int main(void)
{
	ListNode *m_node1 = new ListNode(1);
	ListNode *m_node2 = new ListNode(2);
	ListNode *m_node3 = new ListNode(3);
	ListNode *m_node4 = new ListNode(4);
	ListNode *m_node5 = new ListNode(5);
	ListNode *m_node6 = nullptr;
	m_node1->next = m_node2;
	m_node2->next = m_node3;
	//m_node3->next = m_node4;
	//m_node4->next = m_node5;

	m_node6 = reverseBetween(m_node1,1,1);
	system("pause");
	return 0;
}