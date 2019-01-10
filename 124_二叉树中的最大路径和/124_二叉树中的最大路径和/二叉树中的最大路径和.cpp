#include<iostream>
#include<algorithm>
using namespace std;
/*
����һ���ǿն����������������·���͡�

�����У�·��������Ϊһ������������ڵ������
�ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣
����: [-10,9,20,null,null,15,7]
-10
/ \
9  20
/  \
15   7
���: 42
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxPathSum(TreeNode* root)
{
	int value = INT_MIN;
	int *max_sum = &value;
	dfs(root, max_sum);
	return *max_sum;
}
//dfs�ķ���ֵ�Ǹ������õģ����Բ����ܳ������������֣�
//ֻ�������л�������
int dfs(TreeNode* root, int *max_sum)
{
	if (root == nullptr)
		return 0;
	int l = dfs(root->left, max_sum);
	int r = dfs(root->right, max_sum);
	int sum = root->val;
	if (l > 0)
		sum += l;
	if (r > 0)
		sum += r;
	//��¼���ֵ
	*max_sum = max(*max_sum, sum);
	//�����׽ڵ㷵��ʱ����������˽ڵ㣬���򲻾�����������
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}
int main(void)
{
	system("pause");
	return 0;
}