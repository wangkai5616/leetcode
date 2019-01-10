#include<iostream>
using namespace std;
/*
����������������

1
/  \
2    3
/ \  / \
4  5  6  7
������ĺ����󣬸�������������Ϊ��

1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root)
{
	connectCore(root, nullptr);
}
void connectCore(TreeLinkNode *root, TreeLinkNode *brother)
{
	if (root == nullptr)
		return;
	else
		root->next = brother;
	//���root�����ӵ�nextָ��
	connectCore(root->left, root->right);
	//���root���Һ��ӵ�nextָ��
	if (brother)
		connectCore(root->right, brother->left);
	else
		connectCore(root->right, nullptr);
}
int main(void)
{
	system("pause");
	return 0;
}