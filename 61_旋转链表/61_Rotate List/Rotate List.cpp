#include<iostream>
using namespace std;
/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
*/
/*
思路：
先遍历一遍，得出链表长度 len，注意 k 可能大于 len，因此令 k% = len。
将尾节点 next 指针指向首节点，形成一个环，接着往后跑 len ? k 步，
从这里断开，就是要求的结果了。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
	if(head==nullptr || head->next==nullptr || k<1)
		return head;
	ListNode *node = head;

	int length = 1;
	while (node->next != nullptr)
	{
		length++;
		node = node->next;
	}
	int num = length - k % length;
	node->next = head;//将最初链表的尾和头连起来
	for (int step = 0; step < num; ++step)
		node = node->next;
	head = node->next;//新的头节点
	node->next = nullptr;//断开环
	return head;
}
int main(void)
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);

	node1->next = node2;
	node2->next = node3;

	node1 = rotateRight(node1,1);
	system("pause");
	return 0;
}