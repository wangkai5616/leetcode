#include<iostream>
using namespace std;
/*
����һ�������� L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� 1:
�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};
void reorderList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return;
	ListNode *fast = head;
	ListNode *slow = head;
	//��һ������ƽ���ֿ�
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = nullptr;
	ListNode *head2 = reverse(fast);
	ListNode *head1 = head;
	//�ϲ���������
	while (head1->next)
	{
		ListNode *temp = head1->next;
		head1->next = head2;
		head2 = head2->next;
		head1->next->next = temp;
		head1 = temp;
	}
	head1->next = head2;
}

//��ת����
ListNode *reverse(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *node = head;
	ListNode *tail = nullptr;
	while (node != nullptr)
	{
		ListNode *temp = node->next;
		node->next = tail;
		tail = node;
		node = temp;
	}
	return tail;
}

int main(void)
{
	system("pause");
	return 0;
}