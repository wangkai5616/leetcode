#include<iostream>
using namespace std;
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode* deleteDuplicates(ListNode* head)
 {
	 if (head == nullptr)
		 return head;
	 ListNode *node = head;
	 while (node != NULL)
	 {
		 ListNode *nextNode = node->next;
		 bool needDelete = false;
		 if (nextNode != NULL && node->val == nextNode->val)
			 needDelete = true;
		 if (!needDelete)
			 node = node->next;
		 else
		 {
			 int value = node->val;
			 ListNode *deleteNode = nextNode;
			 while (deleteNode != NULL && deleteNode->val == value)
			 {
				 nextNode = deleteNode->next;
				 delete deleteNode;
				 deleteNode = NULL;
				 deleteNode = nextNode;
			 }
			 node->next = nextNode;
			 node = nextNode;
		 }
	 }
	 return head;
 }
 int main(void)
 {
	 ListNode *node1 = new ListNode(1);
	 ListNode *node2 = new ListNode(1);
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