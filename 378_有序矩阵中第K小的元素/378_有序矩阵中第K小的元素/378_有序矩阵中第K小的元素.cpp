#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
解法一：将所有元素放入堆中进行查找
*/
int kthSmallest(vector<vector<int>>& matrix, int k)
{
	priority_queue<int> q;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			q.emplace(matrix[i][j]);
			if (q.size() > k)
				q.pop();
		}
	}
	return q.top();
}
/*
思路：这题我们也可以用二分查找法来做，我们由于是有序矩阵，那么左上角的数字
一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，然后我们
算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一
行都查找一下 mid，我们使用 upper_bound，这个函数是查找第一个大于目标数的元素，
如果目标数在比该行的尾元素大，则 upper_bound 返回该行元素的个数，如果目标数比
该行首元素小，则 upper_bound 返回0, 我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，
进行二分查找，left 和 right 最终会相等，并且会变成数组中第k小的数字。
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
	int left = matrix[0][0], right = matrix.back().back();
	while (left < right) {
		int mid = left + (right - left) / 2, cnt = 0;
		for (int i = 0; i < matrix.size(); ++i) 
		{
			cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
		}
		if (cnt < k) left = mid + 1;
		else right = mid;
	}
	return left;
}
int main(void)
{
	vector<vector<int>> v = { {1,5,9},{10,11,13},{12,13,15} };
	int k = kthSmallest(v, 18);
	cout << k << endl;
	system("pause");
	return 0;
}