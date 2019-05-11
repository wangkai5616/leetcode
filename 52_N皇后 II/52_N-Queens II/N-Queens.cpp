#include<iostream>
#include<vector>
using namespace std;
/*
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
����һ������ n������ n �ʺ�ͬ�Ľ��������������
*/
void dfs(int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag,int &count);
int totalNQueens(int n)
{
	vector<int> columns(n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ��
	vector<int> main_diag(2 * n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ���Խ���
	vector<int> anti_diag(2 * n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ���Խ���
	int count = 0;//ͳ���������
	dfs( 0, n, columns, main_diag, anti_diag,count);
	return count;
}
void dfs( int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag,int &count)
{
	if (row == n)
	{
		count++;
		return;
	}

	//�����row�������У������i�����У�����ĳһ�У�һ��һ�еĽ��г���
	for (int i = 0; i < n; ++i)
	{
		//��һ�У��Լ���Ԫ�ص����Խ��ߡ����Խ����ϲ�����Ԫ�ش���
		bool ok = columns[i] == 0 && main_diag[row + i] == 0 &&
			anti_diag[row - i + n] == 0;
		//���Ϸ���������һ��
		if (!ok)
			continue;
		//Ŀǰ�Ϸ���������һ�е�Ѱ��
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 1;
		dfs(row + 1, n, columns, main_diag, anti_diag,count);
		//��������,������һ�гɹ���񣬽�����һ�е��ж�
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 0;
	}
}
int main(void)
{
	system("pause");
	return 0;
}