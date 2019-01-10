#include<iostream>
#include<vector>
using namespace std;
/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
0
/ \
-3   9
/   /
-10  5
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return sortedArrayToBSTCore(nums.begin(), nums.end());
}
//二分法
TreeNode* sortedArrayToBSTCore(vector<int>::iterator it1,
	vector<int>::iterator it2)
{
	int length = distance(it1, it2);
	if (length <= 0)
		return nullptr;
	auto mid = it1 + length / 2;
	TreeNode *root = new TreeNode(*mid);
	root->left = sortedArrayToBSTCore(it1, mid);
	root->right = sortedArrayToBSTCore(mid + 1, it2);
	return root;
}
int main(void)
{
	system("pause");
	return 0;
}