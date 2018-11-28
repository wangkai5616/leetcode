#include<iostream>
using namespace std;
/*
�������� �ǿ� ������������ʾ�����Ǹ���������
���У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
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