#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *node = head;
	ListNode *preNode = NULL;
	head = node->next;
	while (node != NULL && node->next != NULL)
	{
		ListNode *curNode = node->next;
		ListNode *nextNode = curNode->next;
		node->next = nextNode;
		curNode->next = node;
		if (preNode == NULL)
			preNode = node;
		else
		{
			preNode->next = curNode;
			preNode = node;
		}
		node = nextNode;
	}
	return head;
}
int main(void)
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	
	node1->next = node2;
	node2->next = node3;
	
	ListNode *node = NULL;
	node = swapPairs(node1);
	cout << node->val<<" "<<node->next->val << endl;
	cout << node->next->next->val <<  endl;
	system("pause");
	return 0;
}