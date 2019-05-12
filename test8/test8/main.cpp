#include<iostream>
#include<memory>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
	if (head == nullptr || head->next==nullptr || k < 1)
		return 0;
	ListNode *node = head;
	int length = 1;
	while (node->next != nullptr)
	{
		node = node->next;
		++length;
	}
	int count = length - k / length - 1;
	if (count == 0)
		return head;
	ListNode *node1 = head;
	while (count--)
		node1 = node1->next;
	node->next = head;
	node = node1->next;
	node->next = nullptr;
	return node;	
}
int main()
{
	
	system("pause");
	return 0;
}





