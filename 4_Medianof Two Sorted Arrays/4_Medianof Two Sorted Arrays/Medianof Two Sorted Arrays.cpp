#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
我们可以考虑从 k 入手。如果我们每次都能够删除一个一定在第 k 大元
素之前的元素，那么我们需要进行 k 次。但是如果每次我们都删除一半呢？由于 A 和 B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设 A 和 B 的元素个数都大于 k/2，我们将 A 的第 k/2 个元素（即 A[k/2-1]）和 B 的第 k/2
个元素（即 B[k/2-1]）进行比较有以下三种情况（为了简化这里先假设 k 为偶数，所得到的结
论对于 k 是奇数也是成立的）：
? A[k/2-1] == B[k/2-1]
? A[k/2-1] > B[k/2-1]
? A[k/2-1] < B[k/2-1]
如果 A[k/2-1] < B[k/2-1]，意味着 A[0] 到 A[k/2-1] 的肯定在 A ∪ B 的 top k 元素的范围
内，换句话说，A[k/2-1] 不可能大于 A ∪ B 的第 k 大元素。
因此，我们可以放心的删除 A 数组的这 k/2 个元素。同理，当 A[k/2-1] > B[k/2-1] 时，可
以删除 B 数组的 k/2 个元素。
当 A[k/2-1] == B[k/2-1] 时，说明找到了第 k 大的元素，直接返回 A[k/2-1] 或 B[k/2-1]
即可。
因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
? 当 A 或 B 是空时，直接返回 B[k-1] 或 A[k-1]；
? 当 k=1 是，返回 min(A[0], B[0])；
? 当 A[k/2-1] == B[k/2-1] 时，返回 A[k/2-1] 或 B[k/2-1]
*/
int findMedianSortedArraysCore(vector<int>::iterator it1, int m,
	vector<int>::iterator it2, int n, int k);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	int total = m + n;
	//两数组之和为奇数
	if (total & 0x1)
		return findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
	//两数组之和为偶数
	else
		return (findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 )+
			findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
}
int findMedianSortedArraysCore(vector<int>::iterator it1, int m, 
	vector<int>::iterator it2, int n,int k)
{
	//始终保证m中的元素小于等于n
	if (m > n)
		return findMedianSortedArraysCore(it2, n, it1, m, k);
	if (m == 0)
		return *(it2+k-1);
	if (k == 1)
		return min(*it1, *it2);
	//把k分到两个数组中，不一定保证能平均分，因为有可能一个数组中元素
	//特别少，另一个特别多
	int a = min(k / 2, m);
	int b = k - a;
	if (*(it1 + a - 1) < *(it2 + b - 1))
		return findMedianSortedArraysCore(it1 + a, m - a, it2, n, k - a);
	else if (*(it2 + b - 1) < *(it1 + a - 1))
		return findMedianSortedArraysCore(it1, m, it2 + b, n - b, k - b);
	//当 A[k/2-1] == B[k/2-1] 时，返回 A[k/2-1] 或 B[k/2-1]
	else
		return *(it1 + a - 1);
}
int main(void)
{
	vector<int> v1 = { 1,3,5,7,9 };
	vector<int> v2 = {2,4,6,8,10 };
	double result = findMedianSortedArrays(v1, v2);
	cout << result << endl;
	system("pause");
	return 0;
}