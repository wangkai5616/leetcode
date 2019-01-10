#include<iostream>
#include<vector>
using namespace std;
//�������
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> result;
	if (numRows == 0)
		return result;
	//��һ��Ԫ��,(1,1)�������vector�Ĵ�С��1��ÿ��Ԫ�ض���1
	result.push_back(vector<int>(1, 1));
	for (int i = 2; i <= numRows; ++i)
	{
		//��i����i��Ԫ��
		vector<int> current(i, 1);
		//����Ӧ���Ǽ�1�������±��Ǵ�0��ʼ��
		const vector<int> &prev = result[i - 2];
		for (int j = 1; j < i - 1; ++j)
			current[j] = prev[j - 1] + prev[j];
		result.push_back(current);
	}
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}