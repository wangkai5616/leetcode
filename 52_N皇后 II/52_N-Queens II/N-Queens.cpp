#include<iostream>
#include<vector>
using namespace std;
/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。
*/
void dfs(int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag,int &count);
int totalNQueens(int n)
{
	vector<int> columns(n, 0);//表示已经放置的皇后占据了哪些列
	vector<int> main_diag(2 * n, 0);//表示已经放置的皇后占据了哪些主对角线
	vector<int> anti_diag(2 * n, 0);//表示已经放置的皇后占据了哪些副对角线
	int count = 0;//统计最后的如果
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

	//上面的row控制了行，这里的i控制列，对于某一行，一列一列的进行尝试
	for (int i = 0; i < n; ++i)
	{
		//这一列，以及该元素的主对角线、副对角线上不能有元素存在
		bool ok = columns[i] == 0 && main_diag[row + i] == 0 &&
			anti_diag[row - i + n] == 0;
		//不合法，尝试下一列
		if (!ok)
			continue;
		//目前合法，进行下一行的寻找
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 1;
		dfs(row + 1, n, columns, main_diag, anti_diag,count);
		//撤销动作,不论上一列成功与否，进行下一列的判断
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 0;
	}
}
int main(void)
{
	system("pause");
	return 0;
}