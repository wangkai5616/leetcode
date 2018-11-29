#include<iostream>
using namespace std;
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
 ListNode* deleteDuplicates(ListNode* head)
 {
	 if (head == NULL)
		 return head;
	 ListNode *node = head;
	 ListNode *preNode = NULL;
	 while (node != NULL)
	 {
		bool needDelete = false;
		ListNode *nextNode = node->next;
		if (nextNode != NULL && nextNode->val == node->val)
			needDelete = true;
		if (!needDelete)
		{
			preNode = node;
			node = node->next;
		}
		else
		{
			ListNode *deleteNode = node;
			int value = node->val;
			while (deleteNode != NULL && deleteNode->val == value)
			{
				nextNode = deleteNode->next;
				delete deleteNode;
				deleteNode = NULL;
				deleteNode = nextNode;
			}
			if (preNode == NULL)
				head = nextNode;
			else
				preNode->next = nextNode;
			node = nextNode;
		}
	 }
	 return head;
 }
 int main(void)
 {
	 ListNode *node1 = new ListNode(1);
	 ListNode *node2 = new ListNode(2);
	 ListNode *node3 = new ListNode(2);
	 ListNode *node4 = new ListNode(3);
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;
	 ListNode *node = NULL;
	 node = deleteDuplicates(node1);
	 cout << node->next->val << endl;
	 system("pause");
	 return 0;
 }