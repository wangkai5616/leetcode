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
//时间复杂度O(n)
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (m == n)
		return head;
	ListNode *node = head;
	ListNode *p = nullptr;
	int k = n - m;
	int s = m;
	//让node节点指向第m个节点，p指向其前一个
	while (m-- > 1)
	{
		p = node;
		node = node->next;
	}
	ListNode *preNode = node;
	ListNode *currentNode = node->next;
	ListNode *nextNode = nullptr;
	//翻转
	while (k-- > 0)
	{
		nextNode = currentNode->next;
		currentNode->next = preNode;
		preNode = currentNode;
		currentNode = nextNode;
	}
	//将第m个节点与第n个节点的下一个节点进行连接
	node->next = currentNode;
	//判断m是否为1，也就是判断前面是否有节点，如有，进行连接
	if (s != 1)
	{
		p->next = preNode;
		return head;
	}
	else
		return preNode;
}

void printListValue(ListNode *node)
{
	while (node != nullptr)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
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
	printListValue(m_node6);
	system("pause");
	return 0;
}