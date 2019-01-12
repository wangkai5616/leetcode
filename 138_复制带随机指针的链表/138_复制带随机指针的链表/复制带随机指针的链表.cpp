#include<iostream>
#include<map>
using namespace std;
/*
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬
��ָ�����ָ�������е��κνڵ��սڵ㡣

Ҫ�󷵻�����������ȿ�����
*/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//˼·�����õ�����ԭ���������ϲ���copy�Ľڵ㣬�ҵ�rand֮���ٷֿ�
RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == nullptr)
		return nullptr;
	RandomListNode *cur = head;
	RandomListNode *next = nullptr;
	/*
	����ԭ����2->1->8�����ھ��ǹ���
	2->2~->1->1~->8->8~,���ʵ���˲�ʹ�ö������ݽṹ��
	��ֻ��ʹ�����޸�����
	*/
	while (cur != nullptr)
	{
		next = cur->next;
		RandomListNode *copy = new RandomListNode(cur->label);
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	cur = head;
	RandomListNode *curCopy = nullptr;
	/*
	������������rand,���2->rand=8,��ô2~->rand=8~;
	*/
	while (cur != nullptr)
	{
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->random = cur->random != nullptr ? cur->random->next : nullptr;
		cur = next;
	}
	RandomListNode *result = head->next;
	cur = head;
	/*
	��������Ĳ��裬���ҵ���2~��1~��8~->rand���������ڵ�copy����
	��ԭ��������һ��2->2~->1->1~->8->8~,������зָ�
	*/
	while (cur != nullptr)
	{
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next != nullptr ? next->next : nullptr;
		cur = next;
	}
	return result;
}

int main(void)
{

	system("pause");
	return 0;
}