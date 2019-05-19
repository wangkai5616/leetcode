#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
���ǿ��Կ��Ǵ� k ���֡��������ÿ�ζ��ܹ�ɾ��һ��һ���ڵ� k ��Ԫ
��֮ǰ��Ԫ�أ���ô������Ҫ���� k �Ρ��������ÿ�����Ƕ�ɾ��һ���أ����� A �� B ��������
�ģ�����Ӧ�ó���������������Ϣ�������ڶ��ֲ��ң�Ҳ�ǳ�������ˡ����򡱡�
���� A �� B ��Ԫ�ظ��������� k/2�����ǽ� A �ĵ� k/2 ��Ԫ�أ��� A[k/2-1]���� B �ĵ� k/2
��Ԫ�أ��� B[k/2-1]�����бȽ����������������Ϊ�˼������ȼ��� k Ϊż�������õ��Ľ�
�۶��� k ������Ҳ�ǳ����ģ���
? A[k/2-1] == B[k/2-1]
? A[k/2-1] > B[k/2-1]
? A[k/2-1] < B[k/2-1]
��� A[k/2-1] < B[k/2-1]����ζ�� A[0] �� A[k/2-1] �Ŀ϶��� A �� B �� top k Ԫ�صķ�Χ
�ڣ����仰˵��A[k/2-1] �����ܴ��� A �� B �ĵ� k ��Ԫ�ء�
��ˣ����ǿ��Է��ĵ�ɾ�� A ������� k/2 ��Ԫ�ء�ͬ���� A[k/2-1] > B[k/2-1] ʱ����
��ɾ�� B ����� k/2 ��Ԫ�ء�
�� A[k/2-1] == B[k/2-1] ʱ��˵���ҵ��˵� k ���Ԫ�أ�ֱ�ӷ��� A[k/2-1] �� B[k/2-1]
���ɡ�
��ˣ����ǿ���дһ���ݹ麯������ô����ʲôʱ��Ӧ����ֹ�أ�
? �� A �� B �ǿ�ʱ��ֱ�ӷ��� B[k-1] �� A[k-1]��
? �� k=1 �ǣ����� min(A[0], B[0])��
? �� A[k/2-1] == B[k/2-1] ʱ������ A[k/2-1] �� B[k/2-1]
*/
int findMedianSortedArraysCore(vector<int>::iterator it1, int m,
	vector<int>::iterator it2, int n, int k);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	int total = m + n;
	//������֮��Ϊ����
	if (total & 0x1)
		return findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
	//������֮��Ϊż��
	else
		return (findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 )+
			findMedianSortedArraysCore(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
}
int findMedianSortedArraysCore(vector<int>::iterator it1, int m, 
	vector<int>::iterator it2, int n,int k)
{
	//ʼ�ձ�֤m�е�Ԫ��С�ڵ���n
	if (m > n)
		return findMedianSortedArraysCore(it2, n, it1, m, k);
	if (m == 0)
		return *(it2+k-1);
	if (k == 1)
		return min(*it1, *it2);
	//��k�ֵ����������У���һ����֤��ƽ���֣���Ϊ�п���һ��������Ԫ��
	//�ر��٣���һ���ر��
	int a = min(k / 2, m);
	int b = k - a;
	if (*(it1 + a - 1) < *(it2 + b - 1))
		return findMedianSortedArraysCore(it1 + a, m - a, it2, n, k - a);
	else if (*(it2 + b - 1) < *(it1 + a - 1))
		return findMedianSortedArraysCore(it1, m, it2 + b, n - b, k - b);
	//�� A[k/2-1] == B[k/2-1] ʱ������ A[k/2-1] �� B[k/2-1]
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