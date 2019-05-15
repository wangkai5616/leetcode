#include<iostream>
#include<vector>
using namespace std;
/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:
*/
/*
思路：这不是链表，可以随便插入，所以采用从后向前排序，这不就省去了移动操作
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	if (n < 1)
		return;
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
		nums1[k--] = nums1[i]>nums2[j] ? nums1[i--] : nums2[j--];
	while (j >= 0)
		nums1[k--] = nums2[j--];
}
int main(void)
{
	system("pause");
	return 0;
}