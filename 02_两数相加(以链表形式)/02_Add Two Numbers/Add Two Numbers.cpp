#include<iostream>
using namespace std;
/*
给出两个 非空 的链表用来表示两个非负的整数。
其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode node(-1);
	int carry = 0;
	ListNode *prev = &node;
	for (ListNode *a = l1, *b = l2; a != nullptr || b != nullptr;
	a = a == nullptr ? nullptr : a->next, b = b == nullptr ? nullptr : b->next, prev = prev->next)
	{
		int num1 = a == nullptr ? 0 : a->val;
		int num2 = b == nullptr ? 0 : b->val;
		int value = (num1 + num2 + carry) % 10;
		carry = (num1 + num2 + carry) / 10;
		prev->next = new ListNode(value);
	}
	if (carry > 0)
		prev->next = new ListNode(carry);
	return node.next;
}
int main(void)
{
	system("pause");
	return 0;
}