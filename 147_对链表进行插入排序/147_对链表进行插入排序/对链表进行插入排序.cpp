#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* findInsertPos(ListNode* head, int value);
ListNode* insertionSortList1(ListNode* head)
{
	ListNode first(INT_MIN);
	//first.next = head;
	//调整插入前后指针的指向
	for (ListNode *cur = head; cur != nullptr;)
	{
		ListNode *pos = findInsertPos(&first, cur->val);
		ListNode *next = cur->next;
		cur->next = pos->next;
		pos->next = cur;
		cur = next;
	}
	return first.next;
}
//找到插入位置
ListNode* findInsertPos(ListNode* head, int value)
{
	ListNode *cur = head;
	ListNode *prev = nullptr;
	for (; cur != nullptr && cur->val <= value;prev=cur,cur=cur->next)
		;
	return prev;
}
int main(void)
{
	ListNode *l1 = new ListNode(4);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(1);
	ListNode *l4 = new ListNode(3);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	ListNode *node = insertionSortList1(l1);
	cout << node->val << node->next->val << node->next->next->next->val << endl;
	system("pause");
	return 0;
}

