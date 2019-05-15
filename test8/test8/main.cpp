#include<iostream>
#include<vector>
using namespace std;
void adjust(vector<int> &arr, int index, int len) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int max_index = index;
	if (left < len && arr[left] > arr[max_index]) max_index = left;
	if (right < len && arr[right] > arr[max_index]) max_index = right;
	if (max_index != index) {
		swap(arr[max_index], arr[index]);
		adjust(arr, max_index, len);
	}
}

void heapSort(vector<int> &arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		adjust(arr, i, len);
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	if (k <= 0 || k > input.size()) {
		vector<int> nullVec;
		return nullVec;
	}
	// 因为要取最小的k个数，所以取前k个数字构建一个最大堆
	// 相反，如果是取最大的k个数，则构建一个最小堆
	vector<int> sortedArray(input.begin(), input.begin() + k);
	heapSort(sortedArray, k);
	// 将后面的数字与这个构建好的二叉堆进行比较 
	for (int i = k; i < input.size(); i++) {
		if (input[i] < sortedArray[0]) {
			sortedArray[0] = input[i];
			adjust(sortedArray, 0, k);
		}
	}
	//前k个元素要是希望有序，就对堆进行挨个排大小
	/*
	for (int i = k - 1; i >= 1; i--) {
		swap(sortedArray[0], sortedArray[i]);
		adjust(sortedArray, 0, i);
	}
	*/
	return sortedArray;
}
int main()
{
	vector<int> v = { 3,8,6,1,9,2,7,4,5 };
	vector<int> result = GetLeastNumbers_Solution(v, 6);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "	";
	cout << endl;
	system("pause");
	return 0;
}
