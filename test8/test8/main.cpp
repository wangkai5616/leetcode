#include<iostream>
#include<string>
using namespace std;
class Base{};
class Derived :public Base {};
int main(void)
{
	auto fun = [](int a,int b)->int{return a+b; };
	cout << fun(2, 3) << endl;
	system("pause");
	return 0;
}


/*
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//�Ľ��İ汾
int HeightOfBinaryTree(TreeNode*pNode, int nMaxDistance) {
	if (pNode == NULL)
		return 0;   //�սڵ�ĸ߶�Ϊ-1
					 //�ݹ�
	int nHeightOfLeftTree = HeightOfBinaryTree(pNode->left, nMaxDistance) + 1;   //�������ĵĸ߶ȼ�1
	int nHeightOfRightTree = HeightOfBinaryTree(pNode->right, nMaxDistance) + 1;   //�������ĸ߶ȼ�1
	int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //��������������ĸ߶ȼ����������ĸ߶�+2
	nMaxDistance = nMaxDistance > nDistance ? nMaxDistance : nDistance;            //�õ���������ֵ
	return nHeightOfLeftTree > nHeightOfRightTree ? nHeightOfLeftTree : nHeightOfRightTree;
}

int main(void)
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node8 = new TreeNode(8);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node5->left = node6;
	node6->right = node7;
	node7->left = node8;
	int result = 0;
	cout << HeightOfBinaryTree(node1,result) << endl;
	cout << result << endl;
	system("pause");
	return 0;
}
*/
