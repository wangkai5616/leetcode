#include<iostream>
#include<vector>
using namespace std;
/*
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
����: 3
���: [1,3,3,1]
*/
vector<int> getRow(int rowIndex)
{
	vector<int> result;
	for (int i = 0; i <= rowIndex; ++i)
	{
		//result��ŵ��ǵ�ǰ�е�Ԫ�أ�������һ�е�ʱ����Խ�������
		for (int j = i - 1; j > 0; --j)//�Ӻ���ǰ���㣬���ݲ��ᱻ����
			result[j] = result[j - 1] + result[j];
		result.push_back(1);//ÿ����Ҫ��ĩβ���1
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}