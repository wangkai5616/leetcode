#include<iostream>
using namespace std;
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;
	ListNode *n1 = head->next;//��ָ��
	ListNode *n2 = head->next->next;//��ָ��
	n2 = head;
	while (n1 != n2)
	{
		if (n2->next == nullptr || n2->next->next == nullptr)
			return nullptr;
		n1 = n1->next;
		n2 = n2->next->next;
	}
	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
}
int main(void)
{
	system("pause");
	return 0;
}