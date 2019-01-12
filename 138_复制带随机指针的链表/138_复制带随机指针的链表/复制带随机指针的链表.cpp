#include<iostream>
#include<map>
using namespace std;
/*
给定一个链表，每个节点包含一个额外增加的随机指针，
该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。
*/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//思路：利用的是在原来的链表上插入copy的节点，找到rand之后再分开
RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == nullptr)
		return nullptr;
	RandomListNode *cur = head;
	RandomListNode *next = nullptr;
	/*
	比如原来是2->1->8，现在就是构成
	2->2~->1->1~->8->8~,这就实现了不使用额外数据结构，
	而只是使用有限个变量
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
	下面做的是找rand,如果2->rand=8,那么2~->rand=8~;
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
	经过上面的步骤，就找到了2~、1~、8~->rand，但是现在的copy链表
	和原链表是在一起2->2~->1->1~->8->8~,下面进行分割
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