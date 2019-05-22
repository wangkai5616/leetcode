#include<iostream>
using namespace std;
//����һ�������ж��������Ƿ��л���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return false;
	ListNode *n1 = head->next;//��ָ��
	ListNode *n2 = head->next->next;//��ָ��
	while (n1 != n2)
	{
		if (n2->next == nullptr || n2->next->next == nullptr)
			return false;
		n1 = n1->next;
		n2 = n2->next->next;
	}
	return true;
}
int main(void)
{
	system("pause");
	return 0;
}