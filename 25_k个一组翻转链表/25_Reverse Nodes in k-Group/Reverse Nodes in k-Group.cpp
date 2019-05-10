#include<iostream>
using namespace std;
/*
����һ������ÿ k ���ڵ�һ����з�ת�������ط�ת�������
k ��һ��������������ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�����ʣ��ڵ㱣��ԭ��˳��
ʾ�� :

�����������1->2->3->4->5
�� k = 2 ʱ��Ӧ������: 2->1->4->3->5
�� k = 3 ʱ��Ӧ������: 3->2->1->4->5
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//�ݹ飬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2)
		return head;
	ListNode *next_group = head;
	for (int i = 0; i < k; ++i)
	{
		if (next_group)
			next_group = next_group->next;
		else
			return head;
	}
	//next_group����һ��k���ڵ��ͷ
	//new_next_group����һ��k���ڵ���µ�ͷ
	//1->2->3<-4,Ȼ��3->nullptr�����ԣ���ʱ,next_group��3��
	//��new_next_group��4
	ListNode *new_next_group = reverseKGroup(next_group, k);
	ListNode *prev = nullptr, *cur = head;
	//ע�⣺�����ж�ָ�����next_group
	while (cur!= next_group)
	{
		ListNode *next = cur->next;
		cur->next = prev ? prev : new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;
}
int main(void)
{
	system("pause");
	return 0;
}