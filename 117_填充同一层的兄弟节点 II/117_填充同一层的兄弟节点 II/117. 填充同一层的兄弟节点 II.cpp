#include<iostream>
using namespace std;
/*
给定二叉树，

1
/  \
2    3
/ \    \
4   5    7
调用你的函数后，该二叉树变为：

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL
注意：与上一题的不同之处是这棵树不是完全二叉树
所以下面的方法可以说是通用的方法
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
	//栈上的对象，函数结束之后就没有了
	TreeLinkNode temp(-1);
	TreeLinkNode *prev = &temp;
	//for循环处理的是每一层
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
	//移到下一层继续处理
	connect(temp.next);
}

int main(void)
{
	system("pause");
	return 0;
}