//回溯法
/**********************************************************************************************************
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格
，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
***********************************************************************************************************/

/*********************************************************************************************************
链接：https://www.nowcoder.com/questionTerminal/6e5207314b5241fb83f2329e89fdecc8
来源：牛客网

1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，


返回1 + 4 个方向的探索值之和。


2.探索时，判断当前节点是否可达的标准为：


1）当前节点在矩阵内；


2）当前节点未被访问过；


3）当前节点满足limit限制。


***********************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
int movingCount(int threshold, int rows, int cols)
{
	bool* flag = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++)
		flag[i] = false;
	int count = moving(threshold, rows, cols, 0, 0, flag);//从（0，0）坐标开始访问
		delete[] flag;
	return count;

}
//计算位置的数值

int getSum(int num)
{
	int sum = 0;
	while (num !=0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}


//计算当前位置是否可以访问
bool is_a_solution(int threshold, int rows, int cols, int i, int j, bool* flag)
{
	if (i >= 0 && i < rows&&i >= 0 && j < cols&&((getSum(i) + getSum(j))<= threshold)&&flag[i*cols + j] == false)
		return true;
	return false;

}

int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
{
	int count = 0;
	if (is_a_solution(threshold, rows, cols, i, j, flag))
	{
		flag[i*cols + j] = true;
		//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可
		//因为如果被访问过，就会加1，不能访问也会标记下访问过。
		count = 1 + moving(threshold, rows, cols, i - 1, j, flag) + moving(threshold, rows, cols, i, j - 1, flag)
			+ moving(threshold, rows, cols, i + 1, j, flag) + moving(threshold, rows, cols, i, j + 1, flag);
	}
	return count;
}
