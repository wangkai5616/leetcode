#include<iostream>
using namespace std;
/*
������������

1
/  \
2    3
/ \    \
4   5    7
������ĺ����󣬸ö�������Ϊ��

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL
ע�⣺����һ��Ĳ�֮ͬ���������������ȫ������
��������ķ�������˵��ͨ�õķ���
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root)
{
	if (root == nullptr)
		return;
	//ջ�ϵĶ��󣬺�������֮���û����
	TreeLinkNode temp(-1);
	TreeLinkNode *prev = &temp;
	//forѭ���������ÿһ��
	for (TreeLinkNode *cur = root; cur; cur = cur->next)
	{
		if (cur->left != nullptr)
		{
			prev->next = cur->left;
			prev = prev->next;
		}
		if (cur->right != nullptr)
		{
			prev->next = cur->right;
			prev = prev->next;
		}
	}
	//�Ƶ���һ���������
	connect(temp.next);
}

int main(void)
{
	system("pause");
	return 0;
}